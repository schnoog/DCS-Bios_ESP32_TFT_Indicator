# DCS-Bios_ESP32_TFT_Indicator

My DCS TFT Display (currently F-16 DED, Gear indicator, airspeed and seconds/mile (I'm a metric thinker, so my feeling for kt and miles isn't the best)


Using a 2.8inch TFT SPI Module with ILI9341 controlle attached to an Lolin S3  ESP32S3 micro controller


### On the PC side installed:

DCS-BIOS ([DCSBIOSKIT - DCS-BIOS](https://github.com/DCSBIOSKit/dcs-bios))

DCS-NEXUS ([ DCSBIOSKIT -DCS-Nexus](https://github.com/DCSBIOSKit/DCS-Nexus " "))



### On the ESP32
TFT_eSPI Library ([Bodmer - TFT_eSPI](https://github.com/Bodmer/TFT_eSPI))

DCS-BIOS Arduino Library ([DCSBIOSKIT- dcs-bios-arduino-library ](https://github.com/DCSBIOSKit/dcs-bios-arduino-library))

### Modifications and other strange things
#### TFT Setup
I created a folder "TFTSETUP" in the Arduino library directory (the same directory which holds the TFT_eSPI library folder).
I placed the `ESP32S3.h` file in that folder an added
`#include <../TFTSETUP/ESP32S3.h>`
to the file 
`TFT_eSPI/User_Setup_Select.h` and commented out all other `#include` statements in the `USER_SETUP_LOADED` section.
 

#### Font
The original font used in the F-16 DED was recreated by several people but all optimized for 11 points font size. That's way too small for that display.
So I used the standard Arial font, exchanged the characters `a` and `o` with an up/down arrow and the degree symbol.
