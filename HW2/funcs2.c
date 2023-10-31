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


int filterOut(const char* inputFilename, const char* target, const char* outputFilename) {
    if (inputFilename == NULL || outputFilename == NULL || target == NULL) {
        return 0;
    }
    FILE* inFile = fopen(inputFilename, "r");
    FILE* outFile = fopen(outputFilename, "w");

    char currLine[100];

    while (fgets(currLine, sizeof(currLine), inFile) != NULL){
        int linePosition = 0;
        int targetPosition = 0;

        while (currLine[linePosition] != '\0') {
            if (currLine[linePosition] == target[targetPosition]) {
                targetPosition++;
                if (target[targetPosition] == '\0') {
                    break;
                }
            } else {
                targetPosition = 0;
            }
            linePosition++;
        }

        fputs(currLine, outFile);
    }
    fclose(inFile);
    fclose(outFile);
    return 1;

}

