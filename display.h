#include <stdint.h>
#ifndef __DISPLAY
#define __DISPLAY

#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#include "ded_data.h"
#include "indicator.h"
#include "Arial-Regular22.h"


#define MYFONT Arial_Regular22

int LC = 0;
TFT_eSPI tft = TFT_eSPI();       // Invoke custom library
TFT_eSprite spr = TFT_eSprite(&tft); // Sprite class needs to be invoked
uint32_t Bitmap = 0xFF8;  // Example bitmap: 111111111000

int16_t CursorX;
int16_t CursorY;
int16_t ToFill;

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


/*
* END SETUP
*/

bool isPrintable(char c) {
    // Check if the character is a printable ASCII character
    return (c > 32 && c <= 126);
}

bool anyPrintable(char arr[]) {
    // Determine the size of the array using strlen
    size_t size = strlen(arr);

    for (size_t i = 0; i < size; ++i) {
        if (isPrintable(arr[i])) {
            // If any element is printable, return true
            return true;
        }
    }
    // No printable character found
    return false;
}


void printBinary(uint32_t value) {
  for (int i = 31; i >= 0; i--) {
    Serial.print((value & (1UL << i)) ? "1" : "0");
  }
  Serial.println(); // Add a newline at the end for better readability
}


bool compareArrays(const char arr1[], const char arr2[]) {
  size_t i = 0;

  // Compare characters until one of them reaches the null terminator
  while (arr1[i] != '\0' && arr2[i] != '\0') {
    if (arr1[i] != arr2[i]) {
      return false;  // Arrays are different
    }
    i++;
  }

  // Check if both arrays reached the null terminator at the same position
  return arr1[i] == '\0' && arr2[i] == '\0';
}




void drawDedLineNew(uint8_t row, const char dedLine[], const char oldLine[]) {
    char truncatedDedLine[26];  // 25 characters plus null terminator
    char truncatedOldLine[26];  // 25 characters plus null terminator



    // Copy at most 25 characters from dedLine to truncatedDedLine
    strncpy(truncatedDedLine, dedLine, 25);
    truncatedDedLine[25] = '\0';  // Ensure null termination

    // Copy at most 25 characters from oldLine to truncatedOldLine
    strncpy(truncatedOldLine, oldLine, 25);
    truncatedOldLine[25] = '\0';  // Ensure null termination

    int16_t RowOffSet = 30;
    int16_t LeftOffSet = 1;
    int16_t TopOffSet;
    int16_t FirstLineTopOffset = 5;
    TopOffSet = (int16_t)row * RowOffSet;
    TopOffSet += FirstLineTopOffset;

    int32_t bitmap = 0;  // Default value if no bitmap is detected

    uint32_t oldbitmap = 0;

    // Check if dedLine contains the bitmap information at the end


    for (int i = 0; i < 4; ++i) {
        bitmap <<= 8;
        bitmap |= (uint8_t)dedLine[28 - i];  // Assuming the last 4 bytes contain the bitmap
    }
    //Serial.println(row);
    //printBinary(bitmap);
    if(row == 11){  //debug output.. 11 will never be reached, set to 0-5 to capture line

      for(int z=0; z < 25 ; z++){
          Serial.print("-");
          Serial.print( dedLine[24 - z]  );
          Serial.print("-");
      }
      Serial.println("");

      printBinary(bitmap);
      Serial.print("Last 4 bytes: ");
      Serial.print("-b 28:");
      Serial.print(dedLine[28],HEX);
      Serial.print("-b 27:");
      Serial.print(dedLine[27],HEX);
      Serial.print("-b 26:");
      Serial.print(dedLine[26],HEX);
      Serial.print("-b 25:");
      Serial.println(dedLine[25],HEX);
    }

    // Draw the cleared area with graphical effects
    tft.setCursor(LeftOffSet, TopOffSet);
    if(!compareArrays(dedLine,oldLine)){
      tft.fillRect(0, TopOffSet, 320, 30,TFT_BLACK);
    }else{
        if(!anyPrintable(truncatedDedLine)){
            tft.fillRect(0, TopOffSet, 320, 30,TFT_BLACK);
        }

    }
    // Draw the current DED line with graphical effects
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setCursor(LeftOffSet, TopOffSet);

    for (int i = 0; i < 25; ++i) {
        // Check if the corresponding bit is set in the Bitmap
        if ((bitmap >> i) & 1) {
          CursorX = tft.getCursorX();
          CursorY = tft.getCursorY();
            tft.fillRect(CursorX,CursorY,12,18,TFT_YELLOW);
            tft.setTextColor(TFT_BLACK, TFT_YELLOW,true);
            tft.setCursor(CursorX, CursorY);
            tft.print(truncatedDedLine[i]);
        } else {
            tft.setTextColor(TFT_YELLOW, TFT_BLACK,true);
            if( truncatedDedLine[i] == '*'){
                CursorX = tft.getCursorX();
                CursorY = tft.getCursorY();
                  tft.fillRect(CursorX,CursorY,12,18,TFT_YELLOW);
                  tft.setTextColor(TFT_BLACK, TFT_YELLOW,true);
                  tft.setCursor(CursorX, CursorY);
            }
            tft.print(truncatedDedLine[i]);
        }
    }
    CursorX = tft.getCursorX();
    CursorY = tft.getCursorY();
    ToFill = 320 - CursorX;
    tft.fillRect(CursorX,CursorY,ToFill,30,TFT_BLACK);    
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
  if(AirSpeed != LastAirSpeed){
    tft.setTextColor(TFT_BLACK, TFT_BLACK,true);
    tft.setCursor(10,180);
    tft.print(LastAirSpeed);
    tft.println(" kt");    
    LastAirSpeed = AirSpeed;
  }
  if(LastSecPerMile != SecPerMile){
    tft.setTextColor(TFT_BLACK, TFT_BLACK,true);
    tft.setCursor(10,210);
    tft.print(LastSecPerMile);
    tft.setTextPadding(160);
    tft.println(" s/mile");
    LastSecPerMile = SecPerMile;
  }

  tft.setTextColor(TFT_RED, TFT_BLACK,true);
  tft.setTextPadding(160);
  tft.setCursor(0,180);
  tft.setTextPadding(160);
  tft.print(" ");
  tft.setCursor(10,180);
//  tft.drawString(dedline,LeftOffSet,TopOffSet);
  tft.print(AirSpeed);
  tft.println(" kt");
  tft.setCursor(0,210);
  tft.setTextPadding(160);
  tft.print(" ");  
  tft.setCursor(10,210);
  tft.print(SecPerMile);
  tft.setTextPadding(160);
  tft.println(" s/mile");
  
}


void loop_tft(){
    tft.loadFont(MYFONT);
    tft.setTextWrap(true, true);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    drawDedLineNew(0,line1,oldline1);
    drawDedLineNew(1,line2,oldline2);
    drawDedLineNew(2,line3,oldline3);
    drawDedLineNew(3,line4,oldline4);
    drawDedLineNew(4,line5,oldline5);
    oldline1 = line1;
    oldline2 = line2;
    oldline3 = line3;
    oldline4 = line4;
    oldline5 = line5;


    //if(PaintNew){
    PaintCycles();
    //}
    paint_speed();

}


#endif	