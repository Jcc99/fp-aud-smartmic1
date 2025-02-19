/*******************************************************************************
Copyright � 2015, STMicroelectronics International N.V.
All rights reserved.

Use and Redistribution are permitted only in accordance with licensing terms 
available at www.st.com under software reference X-CUBE-6180XA1, and provided
that the following conditions are met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of STMicroelectronics nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROTECTED BY STMICROELECTRONICS PATENTS AND COPYRIGHTS.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND
NON-INFRINGEMENT OF INTELLECTUAL PROPERTY RIGHTS ARE DISCLAIMED.
IN NO EVENT SHALL STMICROELECTRONICS INTERNATIONAL N.V. BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
********************************************************************************/

/*
 * @file tof_gestures_platform.h
 * $Date: 2015-11-10 11:21:53 +0100 (Tue, 10 Nov 2015) $
 * $Revision: 2612 $
 */

#ifndef TOF_GESTURES_PLATFORM_H_
#define TOF_GESTURES_PLATFORM_H_

#include "tof_gestures_types.h"
#include "stm32xxx_hal.h"

/**
 * @def GET_TIME_STAMP
 * @brief Return a timestamp in ms (platform-dependent)
 */
#define GET_TIME_STAMP()  (int32_t)HAL_GetTick()

#define ROMABLE_DATA

enum gestures_modules_mask{
    NONE            = 0x0000,
    LC_1            = 0x0001,
    TAP_SWIPE_1     = 0x0002,
    DIRSWIPE_1      = 0x0004,
    MOTION          = 0x0008,
    COVERAGE        = 0x0010,
    LC_TAP_SWIPE_1  = 0x0020,
    TAP_SWIPE_2     = 0x0040,
    TAP_1           = 0x0080,
	SWIPE_1         = 0x0100,
	TAPS_1			= 0x0200,
	DIRSWIPE_TAPS_1 = 0x0400,
};


#if defined(TRACE)
#include "diag/Trace.h"
extern uint32_t tof_gestures_enableDebugModuleMask;
#define TOF_GESTURES_DEBUG_SET_MODULES(gestures_modules_mask) tof_gestures_enableDebugModuleMask = gestures_modules_mask
/**
* @def TOF_GESTURES_DEBUG
* @brief Tracing function for debug purpose
*
* Defining TRACE in compiler command line will enable tracing feature (through #TOF_GESTURES_DEBUG macro) for debug purpose.
* This allows to print any formatted text in STM32 ST-Link utility (printf via SWO viewer).
*/
#define TOF_GESTURES_DEBUG(gestures_modules_mask,fmt, ... ) \
    if(tof_gestures_enableDebugModuleMask & gestures_modules_mask) \
        trace_printf("TOF_GESTURES %s @%d\t" fmt "\n", __func__, GET_TIME_STAMP(), ##__VA_ARGS__);\
    else\
        (void)0;
#else
#define TOF_GESTURES_DEBUG(fmt, ... ) (void)0
#define TOF_GESTURES_DEBUG_SET_MODULES(modulesMask) (void)0
#endif
	
#endif /* TOF_GESTURES_PLATFORM_H_ */
