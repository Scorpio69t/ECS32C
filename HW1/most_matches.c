#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char mostOften;
    int numTimes = 0;
    for (int i = 0; i < strlength(argv[1]); i++) {
        char tempChar = argv[1][i];
        char tempNumTimes = 0;
        for (int j = 0; j < strlength(argv[2]); i++) {
            if (argv[2][j] == tempChar) {
                tempNumTimes++;
            }
        }
        if (tempNumTimes > numTimes) {
            mostOften = tempChar;
        }
    }
    printf("Most often : %c No. times: %d");
    return 0;
}