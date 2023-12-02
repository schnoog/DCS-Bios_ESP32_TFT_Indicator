#ifndef __indicator
#define __indicator

boolean PaintNew = false;
unsigned int NoseWheelDown = 0;
unsigned int LeftWheelDown = 0;
unsigned int RightWheelDown = 0;
unsigned int GearMoving = 0;
unsigned int AirSpeed = 100;
long KnotSecondsPerMile = 3218;
long SecPerMile = 0;
unsigned int LastAirSpeed = 0;
long LastSecPerMile = 0;

void onIasUsIntChange(unsigned int newValue) {
    AirSpeed = newValue;
    SecPerMile = 3218 / (long)AirSpeed;
}


void onLightGearRChange(unsigned int newValue) {
    PaintNew = true;
    if(newValue == 1){
        RightWheelDown = 1;
    }else{
        RightWheelDown = 0;
    }
    /* your code here */
}


void onLightGearNChange(unsigned int newValue) {
    PaintNew = true;
    if(newValue == 1){
        NoseWheelDown = 1;
    }else{
        NoseWheelDown = 0;
    }

}

void onLightGearLChange(unsigned int newValue) {
    PaintNew = true;
    if(newValue == 1){
        LeftWheelDown = 1;
    }else{
        LeftWheelDown = 0;
    }

}

void onLightGearWarnChange(unsigned int newValue) {
    PaintNew = true;
    if(newValue == 1){
        GearMoving = 1;
    }else{
        GearMoving = 0;
    }

}



#endif