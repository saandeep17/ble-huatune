/******************************************************************************
*  Filename:       chipinfo.c
*  Revised:        2015-04-15 13:12:25 +0200 (on, 15 apr 2015)
*  Revision:       43227
*
*  Description:    Collection of functions returning chip information.
*
*  Copyright (c) 2015, Texas Instruments Incorporated
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1) Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*  2) Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3) Neither the name of the ORGANIZATION nor the names of its contributors may
*     be used to endorse or promote products derived from this software without
*     specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
*  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
*  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
*  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
*  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*  POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************/

#include <driverlib/chipinfo.h>

//*****************************************************************************
//
// Internal macros
//
//*****************************************************************************

#define BV( x )   ( 1 << ( x ))


//*****************************************************************************
//
// ChipInfo_GetSupportedProtocol_BV()
//
//*****************************************************************************
ProtocolBitVector_t
ChipInfo_GetSupportedProtocol_BV( void )
{
   return ((ProtocolBitVector_t)( HWREG( PRCM_BASE + 0x1D4 ) & 0x0E ));
}


//*****************************************************************************
//
// ChipInfo_GetPackageType()
//
//*****************************************************************************
PackageType_t
ChipInfo_GetPackageType( void )
{
   PackageType_t packType = (PackageType_t)((
      HWREG( FCFG1_BASE + FCFG1_O_USER_ID     ) &
                          FCFG1_USER_ID_PKG_M ) >>
                          FCFG1_USER_ID_PKG_S ) ;

   if (( packType < PACKAGE_4x4 ) ||
       ( packType > PACKAGE_7x7 )    )
   {
      packType = PACKAGE_Unknown;
   }

   return ( packType );
}


//*****************************************************************************
//
// ChipInfo_GetChipFamily()
//
//*****************************************************************************
ChipFamily_t
ChipInfo_GetChipFamily( void )
{
   ChipFamily_t   chipFam  = FAMILY_Unknown  ;
   uint32_t       waferId                    ;

   waferId = (( HWREG( FCFG1_BASE + FCFG1_O_ICEPICK_DEVICE_ID ) &
                           FCFG1_ICEPICK_DEVICE_ID_WAFER_ID_M ) >>
                           FCFG1_ICEPICK_DEVICE_ID_WAFER_ID_S ) ;

   if (      waferId == 0xB99A )  chipFam = FAMILY_CC26xx       ;
   else if ( waferId == 0xB9BE )  chipFam = FAMILY_CC13xx       ;
   else if ( waferId == 0xBB20 )  chipFam = FAMILY_CC26xxLizard ;

   return ( chipFam );
}


//*****************************************************************************
//
// ChipInfo_GetHwRevision()
//
//*****************************************************************************
HwRevision_t
ChipInfo_GetHwRevision( void )
{
   HwRevision_t   hwRev       = HWREV_Unknown                     ;
   uint32_t       fcfg1Rev    = ChipInfo_GetDeviceIdHwRevCode()   ;
   uint32_t       minorHwRev  = ChipInfo_GetMinorHwRev()          ;

   switch( ChipInfo_GetChipFamily() ) {
   case FAMILY_CC26xx :
      switch ( fcfg1Rev ) {
      case 1 : // CC26xx PG1.0
         hwRev = HWREV_1_0;
         break;
      case 3 : // CC26xx PG2.0
         hwRev = HWREV_2_0;
         break;
      case 7 : // CC26xx PG2.1
         hwRev = HWREV_2_1;
         break;
      case 8 : // CC26xx PG2.2 (or later)
         hwRev = (HwRevision_t)(((uint32_t)HWREV_2_2 ) + minorHwRev );
         break;
      }
      break;
   case FAMILY_CC13xx :
      switch ( fcfg1Rev ) {
      case 0 : // CC13xx PG1.0
         hwRev = HWREV_1_0;
         break;
      case 2 : // CC13xx PG2.0 (or later)
         hwRev = (HwRevision_t)(((uint32_t)HWREV_2_0 ) + minorHwRev );
         break;
      }
      break;
   case FAMILY_CC26xxLizard :
      switch ( fcfg1Rev ) {
      case 0 : // CC26xxLizard PG1.0 (or later)
         hwRev = (HwRevision_t)(((uint32_t)HWREV_1_0 ) + minorHwRev );
         break;
      }
      break;
   }

   return ( hwRev );
}



//*****************************************************************************
// ThisCodeIsBuiltForCC13xxHwRev20AndLater_HaltIfViolated()
//*****************************************************************************
void
ThisCodeIsBuiltForCC13xxHwRev20AndLater_HaltIfViolated( void )
{
   if (( ! ChipInfo_ChipFamilyIsCC13xx()     ) ||
       ( ! ChipInfo_HwRevisionIs_GTEQ_2_0()  )    )
   {
      while(1)
      {
         //
         // This driverlib version is for CC13xx PG2.0 and later.
         // Do nothing - stay here forever
         //
      }
   }
}
