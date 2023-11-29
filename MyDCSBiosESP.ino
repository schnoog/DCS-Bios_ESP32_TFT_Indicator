/*
 * Example using ESP32 mode
 * using https://github.com/DCSBIOSKit/dcs-bios-arduino-library
 */

#include "wificredentials.h"

#define  DCSBIOS_ESP32_WIFI "ESPSlave" // Displayed in DCS-Nexus
#define  DCSBIOS_ESP32_WIFI_MULTICAST // TCP requires the AsyncTCP library.

#define  DCSBIOS_ESP32_WIFI_NEOPIXEL 38 // Optional Neopixel pin. If your ESP32 doesn't have a neopixel, remove this line. Requires Adafruit Neopixel library.
#define  DCSBIOS_ESP32_WIFI_NEOPIXEL_BRIGHTNESS 2
#define  DCSBIOS_ESP32_WIFI_INSTRUMENTATION // Calculates loop() execution time, optional.
#include  "DcsBios.h" // If using PlatformIO, use <DcsBios.h>


//#include "font1.h"
#include "display.h"
#include "pinsettings.h"
#include "ded_data.h"
#include "bindings_F16.h"



void setup() {

  setup_tft();
  //Serial.begin(115200);
  // put your setup code here, to run once:
  DcsBios::setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  DcsBios::loop();
  loop_tft();
}
