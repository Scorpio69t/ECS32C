#include <stdio.h>


int filterOut(const char* inputFilename, const char* target, const char* outputFilename);

int main(void) {
    int retval = filterOut("foo.txt", "xyz", "bar.txt");
    printf("%d\n", retval);
}