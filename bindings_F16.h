
#ifndef __BINDINGS_F16
#define __BINDINGS_F16

#include "pinsettings.h"
#include "ded_data.h"
#include "indicator.h"





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



DcsBios::IntegerBuffer lightGearRBuffer(0x447c, 0x0001, 0, onLightGearRChange);
DcsBios::IntegerBuffer lightGearNBuffer(0x447a, 0x4000, 14, onLightGearNChange);
DcsBios::IntegerBuffer lightGearLBuffer(0x447a, 0x8000, 15, onLightGearLChange);
DcsBios::IntegerBuffer lightGearWarnBuffer(0x447c, 0x0002, 1, onLightGearWarnChange);



DcsBios::IntegerBuffer iasUsIntBuffer(0x042e, 0xffff, 0, onIasUsIntChange);

#endif	