
#ifndef __BINDINGS_F16
#define __BINDINGS_F16

#include "pinsettings.h"
#include "ded_data.h"


/* F-16 LEDs */
DcsBios::LED lightGearWarn(0x447C, 0x2, PIN_GEAR_WARNING);
DcsBios::LED lightGearN(0x447A  , 0x4000, PIN_GEAR_NOSE);
DcsBios::LED lightGearL(0x447A, 0x8000, PIN_GEAR_L);
DcsBios::LED lightGearR(0x447C, 0x1, PIN_GEAR_R);

DcsBios::StringBuffer<29> dedLine1Buffer(0x450a, onDedLine1Change);
DcsBios::StringBuffer<29> dedLine2Buffer(0x4528, onDedLine2Change);
DcsBios::StringBuffer<29> dedLine3Buffer(0x4546, onDedLine3Change);
DcsBios::StringBuffer<29> dedLine4Buffer(0x4564, onDedLine4Change);
DcsBios::StringBuffer<29> dedLine5Buffer(0x4582, onDedLine5Change);



#endif	