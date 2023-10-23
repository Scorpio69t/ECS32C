#include <stdio.h>

int convertToInt(char *strNum)
{
    int convertedInt = 0;
    while (*strNum != '\0')
    {
        convertedInt = (convertedInt * 10) + (*strNum - '0');
        strNum++;
    }
    return convertedInt;
}

int main(int argc, char *argv[])
{
    int c;
    int numSpaces = convertToInt(argv[1]);
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 1; i <= numSpaces; i++)
            {
                putchar(' ');
            }
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
