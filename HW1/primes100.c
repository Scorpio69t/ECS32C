#include <stdio.h>
int num_prime = 0; //The number of prime numbers so far
int counter = 0; //The counter that increments

int main() {
    while (num_prime < 100) {
        
        for (int half_num = 2; half_num < counter/2; half_num++ ) {
            if (counter % half_num == 0) {
                counter++;
                break;
            }
        }
        if (num_prime % 10 == 0) {
            printf("%d  \n", counter);
        } else {
            printf("%d", counter);
        }
        num_prime++;
        counter++;
    }
    return 0;
}
