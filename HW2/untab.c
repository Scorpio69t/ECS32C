#include <stdio.h>

int main(int argc, char* argv[]) {
    int tabSpace = 0;
    int i = 0;
    while(argv[1][i] != '\0') { //Convert to integer
        tabSpace = (tabSpace * 10) + (argv[1][i] - '0');
        i++;
    }
    char c;
    int iter = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spacesTillNext;
            spacesTillNext = tabSpace - iter;
            for (int j = 0; j < spacesTillNext; j++) {
                putchar(' ');
                iter = 0;
            }         
        } else {
            putchar(c);
            if (c == '\n' || iter == tabSpace) {
                iter = 0;
            } else {
                iter++;
            }
        }
    }
    return 0;

}
