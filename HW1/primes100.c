#include <stdio.h>
int num_prime = 0; //The number of prime numbers so far
int counter = 2; //The counter that increments
int half_num; //The divisor that will be used to check for prime, won't go over half of counter

int main() {
    for (counter = 2; num_prime < 100; counter++) {
        int temp = 0;
        for (half_num = 2; half_num <= counter/2; half_num++ ) {
            if (counter % half_num == 0) {
                temp++;
            }
        }
        if (temp == 0) {
            num_prime++;
            if (num_prime % 10 == 0) {
                printf("%d  \n", counter);
            } 
            else if(counter < 10){
                printf("%d    ", counter);
            }
            else if(counter < 100) {
                printf("%d   ", counter);
            }
            else {
                printf("%d  ", counter);
            }
        }
    }
    return 0;
}

