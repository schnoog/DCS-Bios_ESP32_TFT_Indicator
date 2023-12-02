
#ifndef __DED_DATA
#define __DED_DATA

// initialize empty ded lines
char *line1 = (char *)"";
char *line2 = (char *)"";
char *line3 = (char *)"";
char *line4 = (char *)"";
char *line5 = (char *)"";

// old content to check if update
char *oldline1 = (char *)"";
char *oldline2 = (char *)"";
char *oldline3 = (char *)"";
char *oldline4 = (char *)"";
char *oldline5 = (char *)"";

void onDedLine1Change(char* newValue) {
    line1 = newValue;
}

void onDedLine2Change(char* newValue) {
    line2 = newValue;
}


void onDedLine3Change(char* newValue) {
    line3 = newValue;
}

void onDedLine4Change(char* newValue) {
    line4 = newValue;
}


void onDedLine5Change(char* newValue) {
    line5 = newValue;
}



#endif	