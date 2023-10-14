#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char mostOften;
    int numTimes = 0;
    int i, j;
    for (i = 0; i < strlen(argv[1]); i++)
    {
        char tempChar = argv[1][i];
        char tempNumTimes = 0;
        for (j = 0; j < strlen(argv[2]); j++)
        {
            if (argv[2][j] == tempChar)
            {
                tempNumTimes++;
            }
        }
        if (tempNumTimes > numTimes)
        {
            mostOften = tempChar;
            numTimes = tempNumTimes;
        }
    }
    printf("Most often : %c No. times: %d\n", mostOften, numTimes);
    return 0;
}