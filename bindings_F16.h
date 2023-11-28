
#ifndef __BINDINGS_F16
#define __BINDINGS_F16
#include "pinsettings.h"

/* F-16 LEDs */
DcsBios::LED lightGearWarn(0x447C, 0x2, PIN_GEAR_WARNING);
DcsBios::LED lightGearN(0x447A  , 0x4000, PIN_GEAR_NOSE);
DcsBios::LED lightGearL(0x447A, 0x8000, PIN_GEAR_L);
DcsBios::LED lightGearR(0x447C, 0x1, PIN_GEAR_R);



#endif	