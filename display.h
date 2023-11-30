#include <stdint.h>
#ifndef __DISPLAY
#define __DISPLAY

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "ded_data.h"
#include "indicator.h"
#include "Arial-Regular22.h"


#define MYFONT Arial_Regular22


TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&tft); // Sprite class needs to be invoked

void setup_tft(){
  tft.begin();
  tft.fillScreen(TFT_BLACK);
  
  tft.setRotation(1);
   
  spr.setColorDepth(16); // 16 bit colour needed to show anti-aliased fonts

/*
    line1 ="ACB HIJKLMNTUVW";
    line2 ="a123.2 a3345";
    line3 ="HALLO N12o23.23";
    line4 ="1234567890123456789012345";
    line5 =" ";
*/


}


void drawDedLine(uint8_t row, const char dedLine[])
{
  int16_t RowOffSet = 30;
  int16_t LeftOffSet =10;
  int16_t TopOffSet;
  int16_t FirstLineTopOffset = 5;
  TopOffSet = (int16_t)row * RowOffSet;
  TopOffSet += FirstLineTopOffset;  
  tft.setTextColor(TFT_YELLOW, TFT_BLACK,true);
  tft.setTextPadding(320);
  tft.setCursor(LeftOffSet,TopOffSet);
//  tft.drawString(dedline,LeftOffSet,TopOffSet);
  tft.println(dedLine);

}

void PaintCycles(){
  int16_t OffSet_Left_NW = 240;
  int16_t OffSet_Left_LW = 200;
  int16_t OffSet_Left_RW = 280;  
  int16_t OffSet_Left_GearWarn = 240;
  int16_t OffSet_Top_NW = 175;
  int16_t OffSet_Top_LW = 210;
  int16_t OffSet_Top_RW = 210;
  int16_t OffSet_Top_GearWarn = 210;
  if(NoseWheelDown == 1){
      tft.fillCircle(OffSet_Left_NW, OffSet_Top_NW , 20, TFT_GREEN);
  }else{
      tft.fillCircle(OffSet_Left_NW, OffSet_Top_NW , 20, TFT_WHITE);
  }
  if(LeftWheelDown == 1){
    tft.fillCircle(OffSet_Left_LW, OffSet_Top_LW, 20, TFT_GREEN);
  }else{
    tft.fillCircle(OffSet_Left_LW, OffSet_Top_LW, 20, TFT_WHITE);
  }
  
  if(RightWheelDown == 1){
    tft.fillCircle(OffSet_Left_RW, OffSet_Top_RW, 20, TFT_GREEN);
  }else{
    tft.fillCircle(OffSet_Left_RW, OffSet_Top_RW, 20, TFT_WHITE);
  }
  
  if(GearMoving == 1){
    tft.fillCircle(OffSet_Left_GearWarn, OffSet_Top_GearWarn, 10, TFT_RED);
  }else{
    tft.fillCircle(OffSet_Left_GearWarn, OffSet_Top_GearWarn, 10, TFT_WHITE);
  }
  
  


}


void paint_speed(){
  tft.setTextColor(TFT_RED, TFT_BLACK,true);
  tft.setTextPadding(160);
  tft.setCursor(10,180);
//  tft.drawString(dedline,LeftOffSet,TopOffSet);
  tft.print(AirSpeed);
  tft.println(" kt");
  tft.setCursor(10,210);
  tft.print(SecPerMile);
  tft.println(" s/mile");
  
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
    //if(PaintNew){
    PaintCycles();
    //}
    paint_speed();

}


#endif	