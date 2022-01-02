/*
  grbl.h - main Grbl include file
  Part of Grbl

  Copyright (c) 2015-2016 Sungeun K. Jeon for Gnea Research LLC

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef grbl_h
#define grbl_h

// Grbl versioning system
#define GRBL_VERSION "1.1h"
#define GRBL_VERSION_BUILD "20190830"

// Define standard libraries used by Grbl.
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include <util/delay.h>
#include <math.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define the Grbl system include files. NOTE: Do not alter organization.
#include "config.h"
#include "nuts_bolts.h"
#include "settings.h"
#include "system.h"
#include "planner.h"
#include "eeprom.h"
#include "gcode.h"
#include "motion_control.h"
#include "planner.h"
#include "print.h"
#include "protocol.h"
#include "report.h"
#include "serial.h"
#include "stepper.h"
#include "jog.h"

// ---------------------------------------------------------------------------------------
// COMPILE-TIME ERROR CHECKING OF DEFINE VALUES:

#if (REPORT_WCO_REFRESH_BUSY_COUNT < REPORT_WCO_REFRESH_IDLE_COUNT)
  #error "WCO busy refresh is less than idle refresh."
#endif
#if (REPORT_OVR_REFRESH_BUSY_COUNT < REPORT_OVR_REFRESH_IDLE_COUNT)
  #error "Override busy refresh is less than idle refresh."
#endif
#if (REPORT_WCO_REFRESH_IDLE_COUNT < 2)
  #error "WCO refresh must be greater than one."
#endif
#if (REPORT_OVR_REFRESH_IDLE_COUNT < 1)
  #error "Override refresh must be greater than zero."
#endif

#if defined(ENABLE_DUAL_AXIS)
  #if !((DUAL_AXIS_SELECT == X_AXIS) || (DUAL_AXIS_SELECT == Y_AXIS))
    #error "Dual axis currently supports X or Y axes only."
  #endif
  #if defined(DUAL_AXIS_CONFIG_CNC_SHIELD_CLONE) && defined(DUAL_AXIS_CONFIG_PROTONEER_V3_51)
    #error "More than one dual axis configuration found. Select one."
  #endif
  #if !defined(DUAL_AXIS_CONFIG_CNC_SHIELD_CLONE) && !defined(DUAL_AXIS_CONFIG_PROTONEER_V3_51)
    #error "No supported dual axis configuration found. Select one."
  #endif
  #if defined(ENABLE_M7)
    #error "ENABLE_M7 not supported with dual axis feature."
  #endif
#endif

// ---------------------------------------------------------------------------------------

#endif
