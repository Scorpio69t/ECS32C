#include <stdio.h>
int num_prime = 0; //The number of prime numbers so far
int counter = 2; //The counter that increments

int main() {
    while (num_prime < 100) {
        
        for (int half_num = 2; half_num < counter/2; half_num++ ) {
            if (counter % half_num == 0) {
                counter++;
            }
        }
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
        counter++;
    }
    return 0;
}
