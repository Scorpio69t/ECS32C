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
            }
            charptr++;
        }
        if (*charptr == '\0') {
            *firstOffending = strings[i];
            return 0;   
        } 
    }
    return 1;
}
