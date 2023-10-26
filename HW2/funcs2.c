#include <stdio.h>

void sum3(int a, int b, int c, int* sum) {
    if (sum != NULL) {
        *sum = a + b + c;
    }
}



int eachContains(char** strings, char target, unsigned numStrings, char** firstOffending){
    for (int i; i < numStrings; i++) {
        char currStr[] = strings[i];
        int j = 0;
        while (currStr[j] != '\0') {
            if (currStr[j] == target) {
                break;
            j++;
            }
        }
        firstOffending = &currStr[j];
        return 0;
    }
    return 1;
}



int main(void) {
    int s;
    sum3(4, 10, -1, &s);
    printf("%d\n", s);
    sum3(0, 2, -10, &s);
    printf("%d\n", s);
}