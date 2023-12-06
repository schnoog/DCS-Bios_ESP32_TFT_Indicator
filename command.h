#ifndef __commands
#define __commands

#include "indicator.h"
#include "ded_data.h"


#include <SerialCommand.h>
#define SERIALCOMMAND_DEBUG
SerialCommand sCmd;  


void printLine(){
  int aNumber;
  char *arg;

  Serial.println("We're in processCommand");
  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    switch (aNumber)
    {
    case 1:
      Serial.print("line number ");
      Serial.println(aNumber);
      Serial.println(line1);
      break;

    case 2:
      Serial.print("line number ");
      Serial.println(aNumber);
      Serial.println(line2);
      break;

    case 3:
      Serial.print("line number ");
      Serial.println(aNumber);
      Serial.println(line3);
      break;

    case 4:
      Serial.print("line number ");
      Serial.println(aNumber);
      Serial.println(line4);
      break;

    case 5:
      Serial.print("line number ");
      Serial.println(aNumber);
      Serial.println(line5);
      break;


    default:
      break;
    }



  }
  else {
    Serial.println("No argument, expection printline <line number 1-5>");
  }  
}


void setLine() {
  int aNumber;
  char *arg;

  Serial.println("We're in processCommand");
  arg = sCmd.next();
  if (arg != NULL) {
    Serial.print("Setline first argument: ");
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.println(aNumber);
  }
  else {
    Serial.println("No arguments -expecting <line number> <value>");
  }

  arg = sCmd.next();
  if (arg != NULL) {
    //aNumber = atol(arg);
    switch (aNumber)
    {
    case 1:
        Serial.println("Set line1 text");
        line1 = arg;
        line2 = oldline2;
        line3 = oldline3;
        line4 = oldline4;
        line5 = oldline5;
        break;
    case 2:
        Serial.println("Set line2 text");    
        line2 = arg;
        line1 = oldline1;
        line3 = oldline3;
        line4 = oldline4;
        line5 = oldline5;

        break;    
    case 3:
        Serial.println("Set line3 text");    
        line3 = arg;
        line2 = oldline2;
        line1 = oldline1;
        line4 = oldline4;
        line5 = oldline5;

        break;
    case 4:
        Serial.println("Set line4 text");    
        line4 = arg;
        line2 = oldline2;
        line3 = oldline3;
        line1 = oldline1;
        line5 = oldline5;

        break;
    case 5:
        Serial.println("Set line5 text");    
        line5 = arg;
        line2 = oldline2;
        line3 = oldline3;
        line4 = oldline4;
        line1 = oldline1;

        break;
    default:
        break;
    }



  }
  else {
    Serial.println("No second argument");
  }
}

// This gets set as the default handler, and gets called when no other command matches.
void unrecognized(const char *command) {
  Serial.println("What?");
  Serial.println("Commands");
  Serial.println("setline <linenumber> <value>");
  Serial.println("setspeed <Speed to display>");
}


void setSpeed() {
  int aNumber;
  char *arg;

  Serial.println("We're in processCommand");
  arg = sCmd.next();
  if (arg != NULL) {
    aNumber = atoi(arg);    // Converts a char string to an integer
    Serial.print("SETSPEED - First argument was: ");
    Serial.println(aNumber);
    AirSpeed = aNumber;
  }
  else {
    Serial.println("No argument, expection setspeed <SPEED>");
  }

}

void BLIST(){
  DcsBios::sendDcsBiosMessage("ICP_LIST_BTN","1");
  delay(1);
  DcsBios::sendDcsBiosMessage("ICP_LIST_BTN","0");
}

void B7(){
  DcsBios::sendDcsBiosMessage("ICP_BTN_7","1");
  delay(1);
  DcsBios::sendDcsBiosMessage("ICP_BTN_7","0");
}

void BRTN(){
  DcsBios::sendDcsBiosMessage("ICP_DATA_RTN_SEQ_SW","1");
  delay(1);
  DcsBios::sendDcsBiosMessage("ICP_DATA_RTN_SEQ_SW","0");
}

void Command_Setup(){
    sCmd.addCommand("setline", setLine);
    sCmd.addCommand("setspeed", setSpeed);
    sCmd.addCommand("b7", B7);
    sCmd.addCommand("brtn", BRTN);
    sCmd.addCommand("blist", BLIST);
    sCmd.addCommand("printline",printLine);
    sCmd.setDefaultHandler(unrecognized);

}

void Command_Loop(){
    sCmd.readSerial();  
}

#endif