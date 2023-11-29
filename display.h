#include <stdint.h>
#ifndef __DISPLAY
#define __DISPLAY

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "ded_data.h"
//#include "font1.h"
//#include "MyFont.h"

#include "DEDFont32px24.h"


#define MYFONT DEDFont32px24

TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&tft); // Sprite class needs to be invoked

void setup_tft(){
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  
  tft.setRotation(1);
   
  spr.setColorDepth(16); // 16 bit colour needed to show anti-aliased fonts

    line1 ="ACB HIJKLMNTUVW";
    line2 ="a123.2 a3345";
    line3 ="HALLO a222";
    line4 ="1234567890123456789012345";
    line5 ="a2345.67   234.2a";



}


void drawDedLine(uint8_t row, const char dedLine[])
{
  int16_t RowOffSet = 30;
  int16_t LeftOffSet =10;
  int16_t TopOffSet;
  int16_t FirstLineTopOffset = 30;
  TopOffSet = (int16_t)row * RowOffSet;
  TopOffSet += FirstLineTopOffset;  
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  
  tft.setCursor(LeftOffSet,TopOffSet);
//  tft.drawString(dedline,LeftOffSet,TopOffSet);
  tft.println(dedLine);

}

void loop_tft(){
    //tft.fillScreen(TFT_BLACK);
    tft.loadFont(MYFONT);
    tft.setTextWrap(true, true);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    drawDedLine(0,line1);
    drawDedLine(1,line2);
    drawDedLine(2,line3);
    drawDedLine(3,line4);
    drawDedLine(4,line5);

}


#endif	