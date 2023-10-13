#include <stdio.h>


int between(char lowerBound, char upperBound, char target){
// TODO: Implement.
// The below return statement is here in order to prevent
// a compiler error. You probably won't need it once you
// implement this function.
    int lowerBoundAscii = (int)lowerBound;
    int upperBoundAscii = (int)upperBound;
    int targetAscii = (int)target;
    if (65 <= lowerBoundAscii <= 90 && 65 <= upperBoundAscii <= 90) {
        if (lowerBoundAscii <= upperBoundAscii) {
            if (lowerBoundAscii <= targetAscii <= upperBoundAscii) {
                return 1;
            }
        } else {
            return -2;
        }
    } else {
        return -1;
    }
    return 0;
}
