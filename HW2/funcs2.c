#include <stdio.h>

void sum3(int a, int b, int c, int* sum) {
    if (sum != NULL) {
        *sum = a + b + c;
    }
}



int eachContains(char** strings, char target, unsigned numStrings, char** firstOffending){
    for (int i = 0; i < numStrings; i++) {
        char* charptr = strings[i];
        while (*charptr != '\0') {
            if (*charptr == target) {
                break;
            charptr++;
            }
        }
        *firstOffending = strings[i];
        return 0;
    }
    return 1;
}


int filterOut(const char* inputFilename, const char* target, const char* outputFilename){
    
}