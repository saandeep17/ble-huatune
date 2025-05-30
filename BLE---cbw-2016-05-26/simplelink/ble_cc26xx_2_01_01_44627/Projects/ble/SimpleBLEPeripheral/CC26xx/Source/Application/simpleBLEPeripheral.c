/*******************************************************************************
Filename:       simpleBLEPeripheral.c
Revised:        $Date: 2016-01-07 16:59:59 -0800 (Thu, 07 Jan 2016) $
Revision:       $Revision: 44594 $

Description:    This file contains the Simple BLE Peripheral sample 
application for use with the CC2650 Bluetooth Low Energy 
Protocol Stack.

Copyright 2013 - 2015 Texas Instruments Incorporated. All rights reserved.

IMPORTANT: Your use of this Software is limited to those specific rights
granted under the terms of a software license agreement between the user
who downloaded the software, his/her employer (which must be your employer)
and Texas Instruments Incorporated (the "License").  You may not use this
Software unless you agree to abide by the terms of the License. The License
limits your use, and you acknowledge, that the Software may not be modified,
copied or distributed unless embedded on a Texas Instruments microcontroller
or used solely and exclusively in conjunction with a Texas Instruments radio
frequency transceiver, which is integrated into your product.  Other than for
the foregoing purpose, you may not use, reproduce, copy, prepare derivative
works of, modify, distribute, perform, display or sell this Software and/or
its documentation for any purpose.

YOU FURTHER ACKNOWLEDGE AND AGREE THAT THE SOFTWARE AND DOCUMENTATION ARE
PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED,
INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE,
NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL
TEXAS INSTRUMENTS OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT,
NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER
LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE
OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT
OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

Should you have any questions regarding your right to use this Software,
contact Texas Instruments Incorporated at www.TI.com.
*******************************************************************************/

/*********************************************************************
* INCLUDES
*/
#include <string.h>

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Clock.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <ti/sysbios/knl/Queue.h>

#include "hci_tl.h"
#include "gatt.h"
#include "gapgattserver.h"
#include "gattservapp.h"
#include "devinfoservice.h"
#include "simpleGATTprofile.h"

#if defined(SENSORTAG_HW)
#include "bsp_spi.h"
#endif // SENSORTAG_HW

#if defined(FEATURE_OAD) || defined(IMAGE_INVALIDATE)
#include "oad_target.h"
#include "oad.h"
#endif //FEATURE_OAD || IMAGE_INVALIDATE

#include "peripheral.h"
#include "gapbondmgr.h"

#include "osal_snv.h"
#include "ICallBleAPIMSG.h"

#include "util.h"
#include "board_lcd.h"
#include "Board.h"
#include "ht_board_led.h"
#include "ht_board_key.h"
#include "ht_sensor_lis2dh_driver.h"
#include "ht_board_uart.h"
#include <stdlib.h>
#include "ht_board_motor.h"
//#include "ht_board_pwm.h"
#include "simpleBLEPeripheral.h"
#include "ht_board_battery.h"
#include "ht_board_audio.h"
#include "driverlib/Aon_batmon.h"
#include "..\profiles\batt\cc26xx\Battservice.h"


#include <ti/drivers/lcd/LCDDogm1286.h>

/*********************************************************************
* CONSTANTS
*/
// Advertising interval when device is discoverable (units of 625us, 160=100ms)
#define DEFAULT_ADVERTISING_INTERVAL          160

// Limited discoverable mode advertises for 30.72s, and then stops
// General discoverable mode advertises indefinitely
#define DEFAULT_DISCOVERABLE_MODE             GAP_ADTYPE_FLAGS_GENERAL

#ifndef FEATURE_OAD
// Minimum connection interval (units of 1.25ms, 80=100ms) if automatic
// parameter update request is enabled
#define DEFAULT_DESIRED_MIN_CONN_INTERVAL     80

// Maximum connection interval (units of 1.25ms, 800=1000ms) if automatic
// parameter update request is enabled
#define DEFAULT_DESIRED_MAX_CONN_INTERVAL     800
#else
// Minimum connection interval (units of 1.25ms, 8=10ms) if automatic
// parameter update request is enabled
#define DEFAULT_DESIRED_MIN_CONN_INTERVAL     8

// Maximum connection interval (units of 1.25ms, 8=10ms) if automatic
// parameter update request is enabled
#define DEFAULT_DESIRED_MAX_CONN_INTERVAL     8
#endif // FEATURE_OAD

// Slave latency to use if automatic parameter update request is enabled
#define DEFAULT_DESIRED_SLAVE_LATENCY         0

// Supervision timeout value (units of 10ms, 1000=10s) if automatic parameter
// update request is enabled
#define DEFAULT_DESIRED_CONN_TIMEOUT          1000

// Whether to enable automatic parameter update request when a connection is
// formed
#define DEFAULT_ENABLE_UPDATE_REQUEST         TRUE

// Connection Pause Peripheral time value (in seconds)
#define DEFAULT_CONN_PAUSE_PERIPHERAL         6

// How often to perform periodic event (in msec)
#define SBP_PERIODIC_EVT_PERIOD               5000

#ifdef FEATURE_OAD
// The size of an OAD packet.
#define OAD_PACKET_SIZE                       ((OAD_BLOCK_SIZE) + 2)
#endif // FEATURE_OAD

// Task configuration
#define SBP_TASK_PRIORITY                     1

#ifndef SBP_TASK_STACK_SIZE
#define SBP_TASK_STACK_SIZE                   644
#endif

// Internal Events for RTOS application
#define SBP_STATE_CHANGE_EVT                  0x0001
#define SBP_CHAR_CHANGE_EVT                   0x0002
#define SBP_PERIODIC_EVT                      0x0004
#define SBP_CONN_EVT_END_EVT                  0x0008
#define SBC_KEY_CHANGE_EVT                    0x0010

/*********************************************************************
* TYPEDEFS
*/

// App event passed from profiles.
typedef struct
{
  appEvtHdr_t hdr;  // event header.
} sbpEvt_t;

/*********************************************************************
* LOCAL VARIABLES
*/

// Entity ID globally used to check for source and/or destination of messages
static ICall_EntityID selfEntity;

// Semaphore globally used to post events to the application thread
static ICall_Semaphore sem;

// Clock instances for internal periodic events.
static Clock_Struct periodicClock;

// Queue object used for app messages
static Queue_Struct appMsg;
static Queue_Handle appMsgQueue;

#if defined(FEATURE_OAD)
// Event data from OAD profile.
static Queue_Struct oadQ;
static Queue_Handle hOadQ;
#endif //FEATURE_OAD

// events flag for internal application events.
static uint16_t events;

// Task configuration
Task_Struct sbpTask;
Char sbpTaskStack[SBP_TASK_STACK_SIZE];

#define TEST_LED_MODE_ALL_BLINK   0  //��������
#define TEST_LED_MODE_ALL_FLOW    1  //������������
#define TEST_LED_MODE_KEY_CTRL    2  //�������Ƶ�
#define TEST_LED_MODE_HOST_CTRL   3  //�������Ӻ�ֻ����������
//static uint8 my_led_mode = TEST_LED_MODE_ALL_BLINK;

// Profile state and parameters
//static gaprole_States_t gapProfileState = GAPROLE_INIT;

// GAP - SCAN RSP data (max size = 31 bytes)
static uint8_t scanRspData[] =
{
  // complete name
  0x14,   // length of this data
  GAP_ADTYPE_LOCAL_NAME_COMPLETE,
  0x53,   // 'S'
  0x69,   // 'i'
  0x6d,   // 'm'
  0x70,   // 'p'
  0x6c,   // 'l'
  0x65,   // 'e'
  0x42,   // 'B'
  0x4c,   // 'L'
  0x45,   // 'E'
  0x50,   // 'P'
  0x65,   // 'e'
  0x72,   // 'r'
  0x69,   // 'i'
  0x70,   // 'p'
  0x68,   // 'h'
  0x65,   // 'e'
  0x72,   // 'r'
  0x61,   // 'a'
  0x6c,   // 'l'
  
  // connection interval range
  0x05,   // length of this data
  GAP_ADTYPE_SLAVE_CONN_INTERVAL_RANGE,
  LO_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL),   // 100ms
  HI_UINT16(DEFAULT_DESIRED_MIN_CONN_INTERVAL),
  LO_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL),   // 1s
  HI_UINT16(DEFAULT_DESIRED_MAX_CONN_INTERVAL),
  
  // Tx power level
  0x02,   // length of this data
  GAP_ADTYPE_POWER_LEVEL,
  0       // 0dBm
};

// GAP - Advertisement data (max size = 31 bytes, though this is
// best kept short to conserve power while advertisting)
static uint8_t advertData[] =
{
  // Flags; this sets the device to use limited discoverable
  // mode (advertises for 30 seconds at a time) instead of general
  // discoverable mode (advertises indefinitely)
  0x02,   // length of this data
  GAP_ADTYPE_FLAGS,
  DEFAULT_DISCOVERABLE_MODE | GAP_ADTYPE_FLAGS_BREDR_NOT_SUPPORTED,
  
  // service UUID, to notify central devices what services are included
  // in this peripheral
  0x03,   // length of this data
  GAP_ADTYPE_16BIT_MORE,      // some of the UUID's, but not all
#ifdef FEATURE_OAD
  LO_UINT16(OAD_SERVICE_UUID),
  HI_UINT16(OAD_SERVICE_UUID)
#else
    LO_UINT16(SIMPLEPROFILE_SERV_UUID),
    HI_UINT16(SIMPLEPROFILE_SERV_UUID),
#endif //!FEATURE_OAD
};

// GAP GATT Attributes
static uint8_t attDeviceName[GAP_DEVICE_NAME_LEN] = "Simple BLE Peripheral";

// Globals used for ATT Response retransmission
static gattMsgEvent_t *pAttRsp = NULL;
static uint8_t rspTxRetry = 0;

/*********************************************************************
* LOCAL FUNCTIONS
*/

static void SimpleBLEPeripheral_init( void );
static void SimpleBLEPeripheral_taskFxn(UArg a0, UArg a1);

static uint8_t SimpleBLEPeripheral_processStackMsg(ICall_Hdr *pMsg);
static uint8_t SimpleBLEPeripheral_processGATTMsg(gattMsgEvent_t *pMsg);
static void SimpleBLEPeripheral_processAppMsg(sbpEvt_t *pMsg);
static void SimpleBLEPeripheral_processStateChangeEvt( gaprole_States_t newState);
static void SimpleBLEPeripheral_processCharValueChangeEvt(uint8_t paramID);
static void SimpleBLEPeripheral_performPeriodicTask(void);

static void SimpleBLEPeripheral_sendAttRsp(void);
static void SimpleBLEPeripheral_freeAttRsp(uint8_t status);

static void SimpleBLEPeripheral_stateChangeCB(gaprole_States_t newState);
#ifndef FEATURE_OAD
static void SimpleBLEPeripheral_charValueChangeCB(uint8_t paramID);
#endif //!FEATURE_OAD
static void SimpleBLEPeripheral_enqueueMsg(uint8_t event, uint8_t state);

#ifdef FEATURE_OAD
void SimpleBLEPeripheral_processOadWriteCB(uint8_t event, uint16_t connHandle,
                                           uint8_t *pData);
#endif //FEATURE_OAD

static void SimpleBLEPeripheral_clockHandler(UArg arg);
void SimpleBLEPeripheral_keyChangeHandler(uint8 keys);
static void SimpleBLEPeripheral_handleKeys(uint8_t shift, uint8_t keys);

/*********************************************************************
* PROFILE CALLBACKS
*/

// GAP Role Callbacks
static gapRolesCBs_t SimpleBLEPeripheral_gapRoleCBs =
{
  SimpleBLEPeripheral_stateChangeCB     // Profile State Change Callbacks
};

// GAP Bond Manager Callbacks
static gapBondCBs_t simpleBLEPeripheral_BondMgrCBs =
{
  NULL, // Passcode callback (not used by application)
  NULL  // Pairing / Bonding state Callback (not used by application)
};

// Simple GATT Profile Callbacks
#ifndef FEATURE_OAD
static simpleProfileCBs_t SimpleBLEPeripheral_simpleProfileCBs =
{
  SimpleBLEPeripheral_charValueChangeCB // Characteristic value change callback
};
#endif //!FEATURE_OAD

#ifdef FEATURE_OAD
static oadTargetCBs_t simpleBLEPeripheral_oadCBs =
{
  SimpleBLEPeripheral_processOadWriteCB // Write Callback.
};
#endif //FEATURE_OAD

/*********************************************************************
* PUBLIC FUNCTIONS
*/

/*********************************************************************
* @fn      SimpleBLEPeripheral_createTask
*
* @brief   Task creation function for the Simple BLE Peripheral.
*
* @param   None.
*
* @return  None.
*/
void SimpleBLEPeripheral_createTask(void)
{
  Task_Params taskParams;
  
  // Configure task
  Task_Params_init(&taskParams);
  taskParams.stack = sbpTaskStack;
  taskParams.stackSize = SBP_TASK_STACK_SIZE;
  taskParams.priority = SBP_TASK_PRIORITY;
  
  Task_construct(&sbpTask, SimpleBLEPeripheral_taskFxn, &taskParams, NULL);
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_init
*
* @brief   Called during initialization and contains application
*          specific initialization (ie. hardware initialization/setup,
*          table initialization, power up notification, etc), and
*          profile initialization/setup.
*
* @param   None.
*
* @return  None.
*/
static void SimpleBLEPeripheral_init(void)
{
  // ******************************************************************
  // N0 STACK API CALLS CAN OCCUR BEFORE THIS CALL TO ICall_registerApp
  // ******************************************************************
  // Register the current thread as an ICall dispatcher application
  // so that the application can send and receive messages.
  ICall_registerApp(&selfEntity, &sem);
  
  // Hard code the BD Address till CC2650 board gets its own IEEE address
  //uint8 bdAddress[B_ADDR_LEN] = { 0xAD, 0xD0, 0x0A, 0xAD, 0xD0, 0x0A };
  //HCI_EXT_SetBDADDRCmd(bdAddress);
  
  // Set device's Sleep Clock Accuracy
  //HCI_EXT_SetSCACmd(500);
  
  // Create an RTOS queue for message from profile to be sent to app.
  appMsgQueue = Util_constructQueue(&appMsg);
  
  // Create one-shot clocks for internal periodic events.
  Util_constructClock(&periodicClock, SimpleBLEPeripheral_clockHandler,
                      SBP_PERIODIC_EVT_PERIOD, 0, false, SBP_PERIODIC_EVT);
  //add by elvis start 
  Uart_Init();
  ht_Board_initKeys(SimpleBLEPeripheral_keyChangeHandler);
  HalLedInit();
  init_motor();
  Battery_Init();
  init_audio();
  HalLedSet(HAL_LED_1, HAL_LED_MODE_FLASH |(3<<4));
  //LIS2DH_Init();
  //board_pwm_audio(PWM_100_HZ * 7,40);
  //board_pwm_audio(688,40);
  uart_print("cbw  \n\n");
  //add by elvis end
#ifndef SENSORTAG_HW
  //  Board_openLCD();
#endif //SENSORTAG_HW
  
#if SENSORTAG_HW
  // Setup SPI bus for serial flash and Devpack interface
  bspSpiOpen();
#endif //SENSORTAG_HW
  
  // Setup the GAP
  GAP_SetParamValue(TGAP_CONN_PAUSE_PERIPHERAL, DEFAULT_CONN_PAUSE_PERIPHERAL);
  
  // Setup the GAP Peripheral Role Profile
  {
    // For all hardware platforms, device starts advertising upon initialization
    uint8_t initialAdvertEnable = TRUE;
    
    // By setting this to zero, the device will go into the waiting state after
    // being discoverable for 30.72 second, and will not being advertising again
    // until the enabler is set back to TRUE
    uint16_t advertOffTime = 0;
    
    uint8_t enableUpdateRequest = DEFAULT_ENABLE_UPDATE_REQUEST;
    uint16_t desiredMinInterval = DEFAULT_DESIRED_MIN_CONN_INTERVAL;
    uint16_t desiredMaxInterval = DEFAULT_DESIRED_MAX_CONN_INTERVAL;
    uint16_t desiredSlaveLatency = DEFAULT_DESIRED_SLAVE_LATENCY;
    uint16_t desiredConnTimeout = DEFAULT_DESIRED_CONN_TIMEOUT;
    
    // Set the GAP Role Parameters
    GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t),
                         &initialAdvertEnable);
    GAPRole_SetParameter(GAPROLE_ADVERT_OFF_TIME, sizeof(uint16_t),
                         &advertOffTime);
    
    GAPRole_SetParameter(GAPROLE_SCAN_RSP_DATA, sizeof(scanRspData),
                         scanRspData);
    GAPRole_SetParameter(GAPROLE_ADVERT_DATA, sizeof(advertData), advertData);
    
    GAPRole_SetParameter(GAPROLE_PARAM_UPDATE_ENABLE, sizeof(uint8_t),
                         &enableUpdateRequest);
    GAPRole_SetParameter(GAPROLE_MIN_CONN_INTERVAL, sizeof(uint16_t),
                         &desiredMinInterval);
    GAPRole_SetParameter(GAPROLE_MAX_CONN_INTERVAL, sizeof(uint16_t),
                         &desiredMaxInterval);
    GAPRole_SetParameter(GAPROLE_SLAVE_LATENCY, sizeof(uint16_t),
                         &desiredSlaveLatency);
    GAPRole_SetParameter(GAPROLE_TIMEOUT_MULTIPLIER, sizeof(uint16_t),
                         &desiredConnTimeout);
  }
  
  // Set the GAP Characteristics
  GGS_SetParameter(GGS_DEVICE_NAME_ATT, GAP_DEVICE_NAME_LEN, attDeviceName);
  
  // Set advertising interval
  {
    uint16_t advInt = DEFAULT_ADVERTISING_INTERVAL;
    
    GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MIN, advInt);
    GAP_SetParamValue(TGAP_LIM_DISC_ADV_INT_MAX, advInt);
    GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MIN, advInt);
    GAP_SetParamValue(TGAP_GEN_DISC_ADV_INT_MAX, advInt);
  }
  
  // Setup the GAP Bond Manager
  {
    uint32_t passkey = 0; // passkey "000000"
    uint8_t pairMode = GAPBOND_PAIRING_MODE_WAIT_FOR_REQ;
    uint8_t mitm = TRUE;
    uint8_t ioCap = GAPBOND_IO_CAP_DISPLAY_ONLY;
    uint8_t bonding = TRUE;
    
    GAPBondMgr_SetParameter(GAPBOND_DEFAULT_PASSCODE, sizeof(uint32_t),
                            &passkey);
    GAPBondMgr_SetParameter(GAPBOND_PAIRING_MODE, sizeof(uint8_t), &pairMode);
    GAPBondMgr_SetParameter(GAPBOND_MITM_PROTECTION, sizeof(uint8_t), &mitm);
    GAPBondMgr_SetParameter(GAPBOND_IO_CAPABILITIES, sizeof(uint8_t), &ioCap);
    GAPBondMgr_SetParameter(GAPBOND_BONDING_ENABLED, sizeof(uint8_t), &bonding);
  }
  
  // Initialize GATT attributes
  GGS_AddService(GATT_ALL_SERVICES);           // GAP
  GATTServApp_AddService(GATT_ALL_SERVICES);   // GATT attributes
  DevInfo_AddService();                        // Device Information Service
  
#ifndef FEATURE_OAD
  SimpleProfile_AddService(GATT_ALL_SERVICES); // Simple GATT Profile
#endif //!FEATURE_OAD
  
#ifdef FEATURE_OAD
  VOID OAD_addService();                 // OAD Profile
  OAD_register((oadTargetCBs_t *)&simpleBLEPeripheral_oadCBs);
  hOadQ = Util_constructQueue(&oadQ);
#endif
  
#ifdef IMAGE_INVALIDATE
  Reset_addService();
#endif //IMAGE_INVALIDATE
  
  
#ifndef FEATURE_OAD
  // Setup the SimpleProfile Characteristic Values
  {
    uint8_t charValue1 = 1;
    uint8_t charValue2 = 2;
    uint8_t charValue3 = 3;
    uint8_t charValue4 = 4;
    uint8_t charValue5[SIMPLEPROFILE_CHAR5_LEN] = { 1, 2, 3, 4, 5 };
    
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR1, sizeof(uint8_t),
                               &charValue1);
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR2, sizeof(uint8_t),
                               &charValue2);
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR3, sizeof(uint8_t),
                               &charValue3);
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR4, sizeof(uint8_t),
                               &charValue4);
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR5, SIMPLEPROFILE_CHAR5_LEN,
                               charValue5);
  }
  
  // Register callback with SimpleGATTprofile
  SimpleProfile_RegisterAppCBs(&SimpleBLEPeripheral_simpleProfileCBs);
#endif //!FEATURE_OAD
  
  // Start the Device
  VOID GAPRole_StartDevice(&SimpleBLEPeripheral_gapRoleCBs);
  
  // Start Bond Manager
  VOID GAPBondMgr_Register(&simpleBLEPeripheral_BondMgrCBs);
  
  // Register with GAP for HCI/Host messages
  GAP_RegisterForMsgs(selfEntity);
  
  // Register for GATT local events and ATT Responses pending for transmission
  GATT_RegisterForMsgs(selfEntity);
  
#if defined FEATURE_OAD
#if defined (HAL_IMAGE_A)
  LCD_WRITE_STRING("BLE Peripheral A", LCD_PAGE0);
#else
  LCD_WRITE_STRING("BLE Peripheral B", LCD_PAGE0);
#endif // HAL_IMAGE_A
#else
  LCD_WRITE_STRING("BLE Peripheral", LCD_PAGE0);
#endif // FEATURE_OAD
}       

/*********************************************************************
* @fn      SimpleBLEPeripheral_taskFxn
*
* @brief   Application task entry point for the Simple BLE Peripheral.
*
* @param   a0, a1 - not used.
*
* @return  None.
*/
static void SimpleBLEPeripheral_taskFxn(UArg a0, UArg a1)
{
  // Initialize application
  SimpleBLEPeripheral_init();
  
  
  // Application main loop
  for (;;)
  {
    // Waits for a signal to the semaphore associated with the calling thread.
    // Note that the semaphore associated with a thread is signaled when a
    // message is queued to the message receive queue of the thread or when
    // ICall_signal() function is called onto the semaphore.
    ICall_Errno errno = ICall_wait(ICALL_TIMEOUT_FOREVER);
    
    if (errno == ICALL_ERRNO_SUCCESS)
    {
      ICall_EntityID dest;
      ICall_ServiceEnum src;
      ICall_HciExtEvt *pMsg = NULL;
      
      if (ICall_fetchServiceMsg(&src, &dest,(void **)&pMsg) == ICALL_ERRNO_SUCCESS){
        uint8 safeToDealloc = TRUE;
        
        if ((src == ICALL_SERVICE_CLASS_BLE) && (dest == selfEntity)){
          ICall_Event *pEvt = (ICall_Event *)pMsg;
          
          // Check for BLE stack events first
          if (pEvt->signature == 0xffff){
            if (pEvt->event_flag & SBP_CONN_EVT_END_EVT){
              // Try to retransmit pending ATT Response (if any)
              SimpleBLEPeripheral_sendAttRsp();
            }
          }else{
            // Process inter-task message
            safeToDealloc = SimpleBLEPeripheral_processStackMsg(
                                                                (ICall_Hdr *)pMsg);
          }
        }
        
        if (pMsg && safeToDealloc){
          ICall_freeMsg(pMsg);
        }
      }
      
      // If RTOS queue is not empty, process app message.
      while (!Queue_empty(appMsgQueue)){
        sbpEvt_t *pMsg = (sbpEvt_t *)Util_dequeueMsg(appMsgQueue);
        if (pMsg){
          // Process message.
          SimpleBLEPeripheral_processAppMsg(pMsg);
          
          // Free the space from the message.
          ICall_free(pMsg);
        }
      }
    }
    
    if (events & SBP_PERIODIC_EVT){
      events &= ~SBP_PERIODIC_EVT;
      Util_startClock(&periodicClock);
      
      // Perform periodic application task
      SimpleBLEPeripheral_performPeriodicTask();
      
      
      /*   
      // led ��ˮ��  
      if(TEST_LED_MODE_ALL_BLINK == my_led_mode){
      static int count = 0;
      HalLedSet(HAL_LED_1 | HAL_LED_2, HAL_LED_MODE_TOGGLE);
      
      if(++count > 20){
      HalLedSet(HAL_LED_1 | HAL_LED_2, HAL_LED_MODE_OFF);
      my_led_mode = TEST_LED_MODE_ALL_FLOW;
    }
    }else if(TEST_LED_MODE_ALL_FLOW == my_led_mode){
      static uint8 i = 0;
      static int count = 0;
      //uint8 ledshow[] = {HAL_LED_1, HAL_LED_2, HAL_LED_3, HAL_LED_4, HAL_LED_4, HAL_LED_3, HAL_LED_2, HAL_LED_1};
      uint8 ledshow[] = {HAL_LED_1, HAL_LED_1, HAL_LED_2, HAL_LED_2, HAL_LED_1, HAL_LED_1,HAL_LED_2, HAL_LED_2};
      
      HalLedSet(ledshow[i], HAL_LED_MODE_TOGGLE);
      i++;
      i %= (sizeof(ledshow));  
      if(++count > ((sizeof(ledshow))*5)){
      HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
      my_led_mode = TEST_LED_MODE_KEY_CTRL;
    } 
    } 
      */
    }
    
#ifdef FEATURE_OAD
    while (!Queue_empty(hOadQ))
    {
      oadTargetWrite_t *oadWriteEvt = Queue_dequeue(hOadQ);
      
      // Identify new image.
      if (oadWriteEvt->event == OAD_WRITE_IDENTIFY_REQ)
      {
        OAD_imgIdentifyWrite(oadWriteEvt->connHandle, oadWriteEvt->pData);
      }
      // Write a next block request.
      else if (oadWriteEvt->event == OAD_WRITE_BLOCK_REQ)
      {
        OAD_imgBlockWrite(oadWriteEvt->connHandle, oadWriteEvt->pData);
      }
      
      // Free buffer.
      ICall_free(oadWriteEvt);
    }
#endif //FEATURE_OAD
  }
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_processStackMsg
*
* @brief   Process an incoming stack message.
*
* @param   pMsg - message to process
*
* @return  TRUE if safe to deallocate incoming message, FALSE otherwise.
*/
static uint8_t SimpleBLEPeripheral_processStackMsg(ICall_Hdr *pMsg)
{
  uint8_t safeToDealloc = TRUE;
  
  switch (pMsg->event)
  {
  case GATT_MSG_EVENT:
    // Process GATT message
    safeToDealloc = SimpleBLEPeripheral_processGATTMsg(
                                                       (gattMsgEvent_t *)pMsg);
    break;
    
  case HCI_GAP_EVENT_EVENT:
    {
      // Process HCI message
      switch(pMsg->status)
      {
      case HCI_COMMAND_COMPLETE_EVENT_CODE:
        // Process HCI Command Complete Event
        break;
        
      default:
        break;
      }
    }
    break;
    
  default:
    // do nothing
    break;
  }
  
  return (safeToDealloc);
}

//static uint8_t keys_count = 0;
static void SimpleBLEPeripheral_handleKeys(uint8_t shift, uint8_t keys)
{
  //uint8_t lis2dh_id = 0xff;
  uint32_t battValue = 0;
  // AxesRaw_t data;
  
  
  // char in[] = {0,0,0};
  //  char out[] = {1,1,1};
  
  if(keys & KEY_OPEN){
    //   HT_UART_Write(in,sizeof(in));
    HalLedSet(HAL_LED_2 ,HAL_LED_MODE_OFF);
    HalLedSet(HAL_LED_1 ,HAL_LED_MODE_TOGGLE);
    //   keys_count++;
    battValue = getBattValue(ADC_COMPB_IN_AUXIO1);
     uart_print("cbw %d  battValue=%d mV\n\n",__LINE__,battValue);
    //  HT_UART_Write(&keys_count,1);
    //   LIS2DH_GetWHO_AM_I(&lis2dh_id);
    //    HT_UART_Write(&lis2dh_id,1);
    //   HT_UART_Write(out,sizeof(out));
    //   uart_print("id=%#x\n",lis2dh_id);
    
    // LIS2DH_GetAccAxesRaw(&data);
    // uart_print("X=%6d Y=%6d Z=%6d \r\n",data.AXIS_X, data.AXIS_Y, data.AXIS_Z);
    
    // open_motor();
    
    //HalLedSet(HAL_LED_2, HAL_LED_MODE_FLASH |(3<<4));
  }
  
}
/*********************************************************************
* @fn      SimpleBLEPeripheral_processGATTMsg
*
* @brief   Process GATT messages and events.
*
* @return  TRUE if safe to deallocate incoming message, FALSE otherwise.
*/
static uint8_t SimpleBLEPeripheral_processGATTMsg(gattMsgEvent_t *pMsg)
{
  // See if GATT server was unable to transmit an ATT response
  if (pMsg->hdr.status == blePending)
  {
    // No HCI buffer was available. Let's try to retransmit the response
    // on the next connection event.
    if (HCI_EXT_ConnEventNoticeCmd(pMsg->connHandle, selfEntity,
                                   SBP_CONN_EVT_END_EVT) == SUCCESS)
    {
      // First free any pending response
      SimpleBLEPeripheral_freeAttRsp(FAILURE);
      
      // Hold on to the response message for retransmission
      pAttRsp = pMsg;
      
      // Don't free the response message yet
      return (FALSE);
    }
  }
  else if (pMsg->method == ATT_FLOW_CTRL_VIOLATED_EVENT)
  {
    // ATT request-response or indication-confirmation flow control is
    // violated. All subsequent ATT requests or indications will be dropped.
    // The app is informed in case it wants to drop the connection.
    
    // Display the opcode of the message that caused the violation.
    LCD_WRITE_STRING_VALUE("FC Violated:", pMsg->msg.flowCtrlEvt.opcode,
                           10, LCD_PAGE5);
  }    
  else if (pMsg->method == ATT_MTU_UPDATED_EVENT)
  {
    // MTU size updated
    LCD_WRITE_STRING_VALUE("MTU Size:", pMsg->msg.mtuEvt.MTU, 10, LCD_PAGE5);
  }
  
  // Free message payload. Needed only for ATT Protocol messages
  GATT_bm_free(&pMsg->msg, pMsg->method);
  
  // It's safe to free the incoming message
  return (TRUE);
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_sendAttRsp
*
* @brief   Send a pending ATT response message.
*
* @param   none
*
* @return  none
*/
static void SimpleBLEPeripheral_sendAttRsp(void)
{
  // See if there's a pending ATT Response to be transmitted
  if (pAttRsp != NULL)
  {
    uint8_t status;
    
    // Increment retransmission count
    rspTxRetry++;
    
    // Try to retransmit ATT response till either we're successful or
    // the ATT Client times out (after 30s) and drops the connection.
    status = GATT_SendRsp(pAttRsp->connHandle, pAttRsp->method, 
                          &(pAttRsp->msg));
    if ((status != blePending) && (status != MSG_BUFFER_NOT_AVAIL))
    {
      // Disable connection event end notice
      HCI_EXT_ConnEventNoticeCmd(pAttRsp->connHandle, selfEntity, 0);
      
      // We're done with the response message
      SimpleBLEPeripheral_freeAttRsp(status);
    }
    else
    {
      // Continue retrying
      LCD_WRITE_STRING_VALUE("Rsp send retry:", rspTxRetry, 10, LCD_PAGE5);
    }
  }
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_freeAttRsp
*
* @brief   Free ATT response message.
*
* @param   status - response transmit status
*
* @return  none
*/
static void SimpleBLEPeripheral_freeAttRsp(uint8_t status)
{
  // See if there's a pending ATT response message
  if (pAttRsp != NULL)
  {
    // See if the response was sent out successfully
    if (status == SUCCESS)
    {
      LCD_WRITE_STRING_VALUE("Rsp sent, retry:", rspTxRetry, 10, LCD_PAGE5);
    }
    else
    {
      // Free response payload
      GATT_bm_free(&pAttRsp->msg, pAttRsp->method);
      
      LCD_WRITE_STRING_VALUE("Rsp retry failed:", rspTxRetry, 10, LCD_PAGE5);
    }
    
    // Free response message
    ICall_freeMsg(pAttRsp);
    
    // Reset our globals
    pAttRsp = NULL;
    rspTxRetry = 0;
  }
}



/*********************************************************************
* @fn      SimpleBLEPeripheral_processAppMsg
*
* @brief   Process an incoming callback from a profile.
*
* @param   pMsg - message to process
*
* @return  None.
*/
static void SimpleBLEPeripheral_processAppMsg(sbpEvt_t *pMsg)
{
  switch (pMsg->hdr.event)
  {
  case SBP_STATE_CHANGE_EVT:
    SimpleBLEPeripheral_processStateChangeEvt((gaprole_States_t)pMsg->
                                              hdr.state);
    break;
    
  case SBP_CHAR_CHANGE_EVT:
    SimpleBLEPeripheral_processCharValueChangeEvt(pMsg->hdr.state);
    break;
    
  case SBC_KEY_CHANGE_EVT:
    SimpleBLEPeripheral_handleKeys(0, pMsg->hdr.state); 
    break; 
    
  default:
    // Do nothing.
    break;
  }
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_stateChangeCB
*
* @brief   Callback from GAP Role indicating a role state change.
*
* @param   newState - new state
*
* @return  None.
*/
static void SimpleBLEPeripheral_stateChangeCB(gaprole_States_t newState)
{
  SimpleBLEPeripheral_enqueueMsg(SBP_STATE_CHANGE_EVT, newState);
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_processStateChangeEvt
*
* @brief   Process a pending GAP Role state change event.
*
* @param   newState - new state
*
* @return  None.
*/
static void SimpleBLEPeripheral_processStateChangeEvt(gaprole_States_t newState)
{
#ifdef PLUS_BROADCASTER
  static bool firstConnFlag = false;
#endif // PLUS_BROADCASTER
  
  switch ( newState )
  {
  case GAPROLE_STARTED:
    {
      uint8_t ownAddress[B_ADDR_LEN];
      uint8_t systemId[DEVINFO_SYSTEM_ID_LEN];
      
      GAPRole_GetParameter(GAPROLE_BD_ADDR, ownAddress);
      
      // use 6 bytes of device address for 8 bytes of system ID value
      systemId[0] = ownAddress[0];
      systemId[1] = ownAddress[1];
      systemId[2] = ownAddress[2];
      
      // set middle bytes to zero
      systemId[4] = 0x00;
      systemId[3] = 0x00;
      
      // shift three bytes up
      systemId[7] = ownAddress[5];
      systemId[6] = ownAddress[4];
      systemId[5] = ownAddress[3];
      
      DevInfo_SetParameter(DEVINFO_SYSTEM_ID, DEVINFO_SYSTEM_ID_LEN, 
                           systemId);
      
      // Display device address
      LCD_WRITE_STRING(Util_convertBdAddr2Str(ownAddress), LCD_PAGE1);
      LCD_WRITE_STRING("Initialized", LCD_PAGE2);
    }
    break;
    
  case GAPROLE_ADVERTISING:
    LCD_WRITE_STRING("Advertising", LCD_PAGE2);
    break;
    
#ifdef PLUS_BROADCASTER   
    /* After a connection is dropped a device in PLUS_BROADCASTER will continue
    * sending non-connectable advertisements and shall sending this change of 
    * state to the application.  These are then disabled here so that sending 
    * connectable advertisements can resume.
    */
  case GAPROLE_ADVERTISING_NONCONN:
    {
      uint8_t advertEnabled = FALSE;
      
      // Disable non-connectable advertising.
      GAPRole_SetParameter(GAPROLE_ADV_NONCONN_ENABLED, sizeof(uint8_t),
                           &advertEnabled);
      
      advertEnabled = TRUE;
      
      // Enabled connectable advertising.
      GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t),
                           &advertEnabled);
      
      // Reset flag for next connection.
      firstConnFlag = false;
      
      SimpleBLEPeripheral_freeAttRsp(bleNotConnected);
    }
    break;
#endif //PLUS_BROADCASTER   
    
  case GAPROLE_CONNECTED:
    {
      uint8_t peerAddress[B_ADDR_LEN];
      
      GAPRole_GetParameter(GAPROLE_CONN_BD_ADDR, peerAddress);
      
      Util_startClock(&periodicClock);
      
      LCD_WRITE_STRING("Connected", LCD_PAGE2);
      LCD_WRITE_STRING(Util_convertBdAddr2Str(peerAddress), LCD_PAGE3);
      
#ifdef PLUS_BROADCASTER
      // Only turn advertising on for this state when we first connect
      // otherwise, when we go from connected_advertising back to this state
      // we will be turning advertising back on.
      if (firstConnFlag == false)
      {
        uint8_t advertEnabled = FALSE; // Turn on Advertising
        
        // Disable connectable advertising.
        GAPRole_SetParameter(GAPROLE_ADVERT_ENABLED, sizeof(uint8_t),
                             &advertEnabled);
        
        // Set to true for non-connectabel advertising.
        advertEnabled = TRUE;
        
        // Enable non-connectable advertising.
        GAPRole_SetParameter(GAPROLE_ADV_NONCONN_ENABLED, sizeof(uint8_t),
                             &advertEnabled);
        firstConnFlag = true;
      }
#endif // PLUS_BROADCASTER
    }
    break;
    
  case GAPROLE_CONNECTED_ADV:
    LCD_WRITE_STRING("Connected Advertising", LCD_PAGE2);
    break;
    
  case GAPROLE_WAITING:
    Util_stopClock(&periodicClock);
    
    SimpleBLEPeripheral_freeAttRsp(bleNotConnected);
    
    LCD_WRITE_STRING("Disconnected", LCD_PAGE2);
    
    // Clear remaining lines
    LCD_WRITE_STRING("", LCD_PAGE3);
    LCD_WRITE_STRING("", LCD_PAGE4);
    LCD_WRITE_STRING("", LCD_PAGE5);
    break;
    
  case GAPROLE_WAITING_AFTER_TIMEOUT:
    SimpleBLEPeripheral_freeAttRsp(bleNotConnected);
    
    LCD_WRITE_STRING("Timed Out", LCD_PAGE2);
    
    // Clear remaining lines
    LCD_WRITE_STRING("", LCD_PAGE3);
    LCD_WRITE_STRING("", LCD_PAGE4);
    LCD_WRITE_STRING("", LCD_PAGE5);
    
#ifdef PLUS_BROADCASTER
    // Reset flag for next connection.
    firstConnFlag = false;
#endif //#ifdef (PLUS_BROADCASTER)
    break;
    
  case GAPROLE_ERROR:
    LCD_WRITE_STRING("Error", LCD_PAGE2);
    break;
    
  default:
    LCD_WRITE_STRING("", LCD_PAGE2);
    break;
  }
  
  // Update the state
  //gapProfileState = newState;
}

#ifndef FEATURE_OAD
/*********************************************************************
* @fn      SimpleBLEPeripheral_charValueChangeCB
*
* @brief   Callback from Simple Profile indicating a characteristic
*          value change.
*
* @param   paramID - parameter ID of the value that was changed.
*
* @return  None.
*/
static void SimpleBLEPeripheral_charValueChangeCB(uint8_t paramID)
{
  SimpleBLEPeripheral_enqueueMsg(SBP_CHAR_CHANGE_EVT, paramID);
}
#endif //!FEATURE_OAD

/*********************************************************************
* @fn      SimpleBLEPeripheral_processCharValueChangeEvt
*
* @brief   Process a pending Simple Profile characteristic value change
*          event.
*
* @param   paramID - parameter ID of the value that was changed.
*
* @return  None.
*/
static void SimpleBLEPeripheral_processCharValueChangeEvt(uint8_t paramID)
{
#ifndef FEATURE_OAD
  uint8_t newValue;
  switch(paramID)
  {
  case SIMPLEPROFILE_CHAR1:
    SimpleProfile_GetParameter(SIMPLEPROFILE_CHAR1, &newValue);
    
    LCD_WRITE_STRING_VALUE("Char 1:", (uint16_t)newValue, 10, LCD_PAGE4);
    uart_print("feq = %d \n\n",newValue);
    // board_pwm_audio(newValue,40);
    //cbw
    // �������
    
    {
      if(newValue == 0){
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        // board_pwm_stop();
        // play_music();
      }else if(newValue == 1){
        uart_print("feq = %d \n\n",newValue);
        //open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_MODE_REVERSE);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_20);
        //board_pwm_audio(L1,40);
        //play_music(MyScore_zuixuan);

        // play_music();
      }else if(newValue == 2){
        //open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON); 
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_MODE_FORWARD);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_30);
        // board_pwm_audio(L2,40);
        play_music(MyScore_gongxi);
      }else if(newValue == 3){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_FORWARD_FAST | PWM_DURATION_35);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_40);
        //board_pwm_audio(L3,40);
        play_music(MyScore_hetang);
       
        //board_pwm_stop();
        
        //board_pwm_init(HAL_MOTOR_AIN1);

      }else if(newValue == 4){
        //open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN1);
 
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_FORWARD_SLOW | PWM_DURATION_35);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_50);
        board_pwm_audio(L4,40);

      }else if(newValue == 5){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_FAST | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_60);
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(10*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(L5,40);
    
      }else if(newValue == 6){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(L6,40);

      }else if(newValue == 7){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(L7,40);
   
      }else if(newValue == 8){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M1,40);
 
      }else if(newValue == 9){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M2,40);

      }else if(newValue == 10){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M3,40);

      }else if(newValue == 11){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M4,40);
  
      }else if(newValue == 12){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M5,40);

      }else if(newValue == 13){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M6,40);

      }else if(newValue == 14){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_2, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(M7,40);

      }else if(newValue == 15){
        // open_motor(HAL_MOTOR_OFF,HAL_MOTOR_MODE_COAST);
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_OFF);
        HalLedSet(HAL_LED_1, HAL_LED_MODE_ON);
        open_motor(HAL_MOTOR_ON,HAL_MOTOR_PWM_REVERSE_SLOW | PWM_DURATION_65);
        set_cutoff_current(BATTERY_CUTOFF_CURRENT_70);        
        // board_pwm_stop();
        //board_pwm_init(HAL_MOTOR_AIN2);
        // board_pwm_start(100*1000,70,HAL_MOTOR_AIN2);
        board_pwm_audio(H1,40);

      }else{
        HalLedSet(HAL_LED_1 | HAL_LED_2 , HAL_LED_MODE_ON);
        board_pwm_audio(PWM_100_HZ * 2,40);

      }
    }
    
    break;
    
  case SIMPLEPROFILE_CHAR3:
    SimpleProfile_GetParameter(SIMPLEPROFILE_CHAR3, &newValue);
    
    LCD_WRITE_STRING_VALUE("Char 3:", (uint16_t)newValue, 10, LCD_PAGE4);
    break;
    
  default:
    // should not reach here!
    break;
  }
#endif //!FEATURE_OAD
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_performPeriodicTask
*
* @brief   Perform a periodic application task. This function gets called
*          every five seconds (SBP_PERIODIC_EVT_PERIOD). In this example,
*          the value of the third characteristic in the SimpleGATTProfile
*          service is retrieved from the profile, and then copied into the
*          value of the the fourth characteristic.
*
* @param   None.
*
* @return  None.
*/
static void SimpleBLEPeripheral_performPeriodicTask(void)
{
#ifndef FEATURE_OAD
  uint8_t valueToCopy;
  
  // Call to retrieve the value of the third characteristic in the profile
  if (SimpleProfile_GetParameter(SIMPLEPROFILE_CHAR3, &valueToCopy) == SUCCESS)
  {
    // Call to set that value of the fourth characteristic in the profile.
    // Note that if notifications of the fourth characteristic have been
    // enabled by a GATT client device, then a notification will be sent
    // every time this function is called.
    SimpleProfile_SetParameter(SIMPLEPROFILE_CHAR4, sizeof(uint8_t),
                               &valueToCopy);
  }
#endif //!FEATURE_OAD
}


#if defined(FEATURE_OAD)
/*********************************************************************
* @fn      SimpleBLEPeripheral_processOadWriteCB
*
* @brief   Process a write request to the OAD profile.
*
* @param   event      - event type:
*                       OAD_WRITE_IDENTIFY_REQ
*                       OAD_WRITE_BLOCK_REQ
* @param   connHandle - the connection Handle this request is from.
* @param   pData      - pointer to data for processing and/or storing.
*
* @return  None.
*/
void SimpleBLEPeripheral_processOadWriteCB(uint8_t event, uint16_t connHandle,
                                           uint8_t *pData)
{
  oadTargetWrite_t *oadWriteEvt = ICall_malloc( sizeof(oadTargetWrite_t) + \
    sizeof(uint8_t) * OAD_PACKET_SIZE);
  
  if ( oadWriteEvt != NULL )
  {
    oadWriteEvt->event = event;
    oadWriteEvt->connHandle = connHandle;
    
    oadWriteEvt->pData = (uint8_t *)(&oadWriteEvt->pData + 1);
    memcpy(oadWriteEvt->pData, pData, OAD_PACKET_SIZE);
    
    Queue_enqueue(hOadQ, (Queue_Elem *)oadWriteEvt);
    
    // Post the application's semaphore.
    Semaphore_post(sem);
  }
  else
  {
    // Fail silently.
  }
}
#endif //FEATURE_OAD

/*********************************************************************
* @fn      SimpleBLEPeripheral_clockHandler
*
* @brief   Handler function for clock timeouts.
*
* @param   arg - event type
*
* @return  None.
*/
static void SimpleBLEPeripheral_clockHandler(UArg arg)
{
  // Store the event.
  events |= arg;
  
  // Wake up the application.
  Semaphore_post(sem);
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_keyChangeHandler
*
* @brief   Key event handler function
*
* @param   a0 - ignored
*
* @return  none
*/
void SimpleBLEPeripheral_keyChangeHandler(uint8 keys)
{
  SimpleBLEPeripheral_enqueueMsg(SBC_KEY_CHANGE_EVT, keys);
}

/*********************************************************************
* @fn      SimpleBLEPeripheral_enqueueMsg
*
* @brief   Creates a message and puts the message in RTOS queue.
*
* @param   event - message event.
* @param   state - message state.
*
* @return  None.
*/
static void SimpleBLEPeripheral_enqueueMsg(uint8_t event, uint8_t state)
{
  sbpEvt_t *pMsg;
  
  // Create dynamic pointer to message.
  if ((pMsg = ICall_malloc(sizeof(sbpEvt_t))))
  {
    pMsg->hdr.event = event;
    pMsg->hdr.state = state;
    
    // Enqueue the message.
    Util_enqueueMsg(appMsgQueue, sem, (uint8*)pMsg);
  }
}

/*********************************************************************
*********************************************************************/
