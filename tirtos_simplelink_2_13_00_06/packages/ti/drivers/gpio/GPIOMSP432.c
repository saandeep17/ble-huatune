/*
 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdint.h>
#include <stdbool.h>
#if defined(__IAR_SYSTEMS_ICC__)
#include <intrinsics.h>
#endif

/*
 * By default disable both asserts and log for this module.
 * This must be done before DebugP.h is included.
 */
#ifndef DebugP_ASSERT_ENABLED
#define DebugP_ASSERT_ENABLED 0
#endif
#ifndef DebugP_LOG_ENABLED
#define DebugP_LOG_ENABLED 0
#endif

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSP432.h>
#include <ti/drivers/ports/DebugP.h>
#include <ti/drivers/ports/HwiP.h>

/* driverlib header files */
#include <rom.h>
#include <rom_map.h>
#include <gpio.h>

/*
 * Map GPIO_INT types to corresponding MSP432 interrupt options
 */
static const uint8_t interruptType[] = {
    0,                              /* GPIO_CFG_IN_INT_NONE */
    GPIO_HIGH_TO_LOW_TRANSITION,    /* 1 = Interrupt on falling edge */
    GPIO_LOW_TO_HIGH_TRANSITION,    /* 2 = Interrupt on rising edge */
    GPIO_HIGH_TO_LOW_TRANSITION |   /* 3 = Interrupt on both edges */
    GPIO_LOW_TO_HIGH_TRANSITION,    /* (Not supported on MSP432) */
    GPIO_INPUT_PIN_LOW,             /* 4 = Interrupt on low level */
    GPIO_INPUT_PIN_HIGH             /* 5 = Interrupt on high level */
};

/*
 * Table of port interrupt vector numbers
 * Used by setCallback() to create Hwis.
 * Up to NUM_PORTS port interrupts must be supported
 */
static const uint8_t portInterruptIds[] = {
    INT_PORT1, INT_PORT2, INT_PORT3,
    INT_PORT4, INT_PORT5, INT_PORT6
};

/*
 * There are 11 8-bit ports total (1-10 and J)
 * but only 6 ports support interrupts
 */
#define NUM_PORTS           6
#define NUM_PINS_PER_PORT   8

/*
 * Extracts the GPIO interrupt type from the pinConfig.  Value to index into the
 * interruptType table.
 */
#define getIntTypeNumber(pinConfig) \
    ((pinConfig & GPIO_CFG_INT_MASK) >> GPIO_CFG_INT_LSB)

/* uninitialized callbackInfo pinIndex */
#define CALLBACK_INDEX_NOT_CONFIGURED 0xFF

/*
 * Device specific interpretation of the GPIO_PinConfig content
 */
typedef struct PinConfig {
    uint8_t pin;
    uint8_t port;
    uint16_t config;
} PinConfig;

/*
 * User defined pin indexes assigned to a port's 8 pins.
 * Used by port interrupt function to located callback assigned
 * to a pin.
 */
typedef struct PortCallbackInfo {
    /*
     * the port's 8 corresponding
     * user defined pinId indices
     */
    uint8_t pinIndex[NUM_PINS_PER_PORT];
} PortCallbackInfo;

/*
 * Table of portCallbackInfos.
 * One for each port.
 */
static PortCallbackInfo gpioCallbackInfo[NUM_PORTS];

/*
 * bit mask used to determine if a Hwi has been created/constructed
 * for a port already.
 * up to NUM_PORTS port interrupts must be supported
 */
static uint8_t portHwiCreatedBitMask = 0;

#if DebugP_ASSERT_ENABLED
/*
 * internal boolean to confirm that GPIO_init() has been called
 */
static bool initCalled = false; /* Also used to check status for initialization */
#endif

extern const GPIOMSP432_Config GPIOMSP432_config;

/*
 *  ======== getPinNumber ========
 *
 *  Internal function to efficiently find the index of the right most set bit.
 */
static inline uint32_t getPinNumber(uint32_t x) {
#if defined(__TI_COMPILER_VERSION__)
    return __clz(__rbit(x));
#elif defined(codered) || defined(__GNUC__) || defined(sourcerygxx)
    return __builtin_ctz(x);
#elif defined(__IAR_SYSTEMS_ICC__)
    return __CLZ(__RBIT(x));
#elif defined(rvmdk) || defined(__ARMCC_VERSION)
    return __clz(__rbit(x));
#else
    #error "Unsupported compiler used"
#endif
}

/*
 *  ======== GPIO_clearInt ========
 */
void GPIO_clearInt(unsigned int index)
{
    uintptr_t  key;
    PinConfig *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);

    /* Make atomic update */
    key = HwiP_disable();

    /* Clear GPIO interrupt flag */
    MAP_GPIO_clearInterruptFlag(config->port, config->pin);

    HwiP_restore(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupt flag cleared",
        config->port, config->pin);
}

/*
 *  ======== GPIO_disableInt ========
 */
void GPIO_disableInt(unsigned int index)
{
    uintptr_t  key;
    PinConfig *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);

    /* Make atomic update */
    key = HwiP_disable();

    /* Disable GPIO interrupt */
    MAP_GPIO_disableInterrupt(config->port, config->pin);

    HwiP_restore(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupts disabled", config->port,
        config->pin);
}

/*
 *  ======== GPIO_enableInt ========
 */
void GPIO_enableInt(unsigned int index)
{
    uintptr_t  key;
    PinConfig *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);

    /* Make atomic update */
    key = HwiP_disable();

    /* Enable GPIO interrupt */
    MAP_GPIO_enableInterrupt(config->port, config->pin);

    HwiP_restore(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x interrupts enabled", config->port,
        config->pin);
}

/*
 *  ======== GPIO_hwiIntFxn ========
 *  Hwi function that processes GPIO interrupts.
 */
void GPIO_hwiIntFxn(uintptr_t portIndex)
{
    unsigned int      bitNum;
    unsigned int      pinIndex;
    uint32_t          port;
    uint32_t          pins;
    PortCallbackInfo *portCallbackInfo;

    portCallbackInfo = &gpioCallbackInfo[portIndex];
    port = portIndex + 1;

    /* Find out which pins have their interrupt flags set */
    pins = MAP_GPIO_getEnabledInterruptStatus(port);

    /* clear all the set bits at once */
    MAP_GPIO_clearInterruptFlag(port, pins);

    /* Match each set bit to its corresponding callback function */
    while (pins) {
        /* gets the lowest order set bit number */
        bitNum = getPinNumber(pins);
        pinIndex = portCallbackInfo->pinIndex[bitNum];
        /* only call plugged callbacks */
        if (pinIndex != CALLBACK_INDEX_NOT_CONFIGURED) {
            GPIOMSP432_config.callbacks[pinIndex]();
        }
        pins &= ~(1 << bitNum);
    }
}

/*
 *  ======== GPIO_init ========
 */
void GPIO_init()
{
    unsigned int i, j;

#if DebugP_ASSERT_ENABLED
    initCalled = true;
#endif
    for (i = 0; i < NUM_PORTS; i++) {
        for (j = 0; j < NUM_PINS_PER_PORT; j++) {
            gpioCallbackInfo[i].pinIndex[j] = CALLBACK_INDEX_NOT_CONFIGURED;
        }
    }

    /*
     * Configure pins and create Hwis per static array content
     */
    for (i = 0; i < GPIOMSP432_config.numberOfPinConfigs; i++) {
        if ((GPIOMSP432_config.pinConfigs[i] & GPIO_DO_NOT_CONFIG) !=
            GPIO_DO_NOT_CONFIG) {
            GPIO_setConfig(i, GPIOMSP432_config.pinConfigs[i]);
        }
        if (i < GPIOMSP432_config.numberOfCallbacks) {
            if (GPIOMSP432_config.callbacks[i] != NULL) {
                /* create Hwi as necessary */
                GPIO_setCallback(i, GPIOMSP432_config.callbacks[i]);
            }
        }
    }
}

/*
 *  ======== GPIO_read ========
 */
unsigned int GPIO_read(unsigned int index)
{
    unsigned int value;
    PinConfig   *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);

    value = MAP_GPIO_getInputPinValue(config->port, config->pin);

    DebugP_log3("GPIO: port 0x%x, pin 0x%x read 0x%x", config->port,
        config->pin, value);

    return (value);
}

/*
 *  ======== GPIO_setCallback ========
 */
void GPIO_setCallback(unsigned int index, GPIO_CallbackFxn callback)
{
    unsigned int key;
    uint32_t     pinNum;
    uint32_t     portIndex;
    PinConfig   *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfCallbacks);

    /*
     * plug the pin index into the corresponding
     * port's callbackInfo pinIndex entry
     */
    pinNum = getPinNumber(config->pin);
    portIndex = config->port - 1;

    /* Make atomic update */
    key = HwiP_disable();

    if (callback == NULL) {
        gpioCallbackInfo[portIndex].pinIndex[pinNum] =
            CALLBACK_INDEX_NOT_CONFIGURED;
    }
    else {
        gpioCallbackInfo[portIndex].pinIndex[pinNum] = index;
    }

    /*
     * Only update callBackFunctions entry if different.
     * This allows the callBackFunctions array to be in flash
     * for static systems.
     */
    if (GPIOMSP432_config.callbacks[index] != callback) {
        GPIOMSP432_config.callbacks[index] = callback;
    }

    HwiP_restore(key);
}

/*
 *  ======== GPIO_setConfig ========
 */
void GPIO_setConfig(unsigned int index, GPIO_PinConfig pinConfig)
{
    uintptr_t      key;
    uint32_t       pin;
    uint32_t       port;
    uint32_t       portIndex;
    uint32_t       portBitMask;
    HwiP_Params    hwiParams;
    HwiP_Handle    hwiHandle;
    GPIO_PinConfig gpioPinConfig;
    PinConfig     *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);

    port = config->port;
    pin = config->pin;

    if ((pinConfig & GPIO_CFG_IN_INT_ONLY) == 0) {
        /* Make atomic update */
        key = HwiP_disable();

        if (pinConfig & GPIO_CFG_INPUT) {
            /* configure input */
            if ((pinConfig & GPIO_CFG_IN_PU) == GPIO_CFG_IN_PU) {
                MAP_GPIO_setAsInputPinWithPullUpResistor(port, pin);
            }
            else if ((pinConfig & GPIO_CFG_IN_PD) == GPIO_CFG_IN_PD) {
                MAP_GPIO_setAsInputPinWithPullDownResistor(port, pin);
            }
            else {
                MAP_GPIO_setAsInputPin(port, pin);
            }
        }
        else {
            /* configure output */
            MAP_GPIO_setAsOutputPin(port, pin);
            if ((pinConfig & GPIO_CFG_OUT_STRENGTH_MASK) ==
                GPIO_CFG_OUT_STR_LOW) {
                MAP_GPIO_setDriveStrengthLow(port, pin);
            }
            else {
                /* Map MED and HIGH to high */
                MAP_GPIO_setDriveStrengthHigh(port, pin);
            }
            if (pinConfig & GPIO_CFG_OUT_HIGH) {
                MAP_GPIO_setOutputHighOnPin(port, pin);
            }
            else {
                MAP_GPIO_setOutputLowOnPin(port, pin);
            }
        }

        /* Update the table entry with the latest values */
        gpioPinConfig = GPIOMSP432_config.pinConfigs[index];
        gpioPinConfig &= ~GPIO_CFG_IO_MASK;
        gpioPinConfig |= (pinConfig & GPIO_CFG_IO_MASK);
        GPIOMSP432_config.pinConfigs[index] = gpioPinConfig;

        HwiP_restore(key);
    }

    /* Set type of interrupt and then enable it */
    if (pinConfig & GPIO_CFG_INT_MASK) {
        portIndex = config->port - 1;
        portBitMask = 1 << portIndex;

        /* if Hwi has not already been created, do so */
        if ((portHwiCreatedBitMask & portBitMask) == 0) {
            HwiP_Params_init(&hwiParams);
            hwiParams.arg = (uintptr_t)portIndex;
            hwiParams.priority = GPIOMSP432_config.intPriority;
            hwiHandle = HwiP_create(portInterruptIds[portIndex], GPIO_hwiIntFxn,
                &hwiParams);
            if (hwiHandle == NULL) {
                /* Error creating Hwi */
                DebugP_log1("GPIO: Error crating Hwi for GPIO Port %d",
                    config->port);
                return;
            }

        }

        key = HwiP_disable();

        /* Mark the Hwi as created */
        portHwiCreatedBitMask |= portBitMask;

        MAP_GPIO_interruptEdgeSelect(port, pin,
            interruptType[getIntTypeNumber(pinConfig)]);
        MAP_GPIO_clearInterruptFlag(port, pin);

        /* Update the table entry */
        gpioPinConfig = GPIOMSP432_config.pinConfigs[index];
        gpioPinConfig &= ~GPIO_CFG_INT_MASK;
        gpioPinConfig |= (pinConfig & GPIO_CFG_INT_MASK);
        GPIOMSP432_config.pinConfigs[index] = gpioPinConfig;

        HwiP_restore(key);
    }
}

/*
 *  ======== GPIO_toggle ========
 */
void GPIO_toggle(unsigned int index)
{
    uintptr_t  key;
    PinConfig *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);
    DebugP_assert((GPIOMSP432_config.pinConfigs[index] & GPIO_CFG_INPUT) ==
        GPIO_CFG_OUTPUT);

    /* Make atomic update */
    key = HwiP_disable();

    MAP_GPIO_toggleOutputOnPin(config->port, config->pin);

    /* Update config table entry with value written */
    GPIOMSP432_config.pinConfigs[index] ^= GPIO_CFG_OUT_HIGH;

    HwiP_restore(key);

    DebugP_log2("GPIO: port 0x%x, pin 0x%x toggled", config->port, config->pin);
}

/*
 *  ======== GPIO_write ========
 */
void GPIO_write(unsigned int index, unsigned int value)
{
    uintptr_t  key;
    PinConfig *config = (PinConfig *) &GPIOMSP432_config.pinConfigs[index];

    DebugP_assert(initCalled && index < GPIOMSP432_config.numberOfPinConfigs);
    DebugP_assert((GPIOMSP432_config.pinConfigs[index] & GPIO_CFG_INPUT) ==
        GPIO_CFG_OUTPUT);

    key = HwiP_disable();

    /* Clear output from pinConfig */
    GPIOMSP432_config.pinConfigs[index] &= ~GPIO_CFG_OUT_HIGH;

    if (value) {
        MAP_GPIO_setOutputHighOnPin(config->port, config->pin);

        /* Set the pinConfig output bit to high */
        GPIOMSP432_config.pinConfigs[index] |= GPIO_CFG_OUT_HIGH;
    }
    else {
        MAP_GPIO_setOutputLowOnPin(config->port, config->pin);
    }

    HwiP_restore(key);

    DebugP_log3("GPIO: port 0x%x, pin 0x%x wrote 0x%x", config->port,
        config->pin, value);
}
