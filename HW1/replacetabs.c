#include <stdio.h>

int main(int argc, char *argv[])
{
    int c;
    char numSpaces[] = argv[1];
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            for (int i = 1; i < numSpaces; i++)
            {
                putchar(' ');
            }
        }
    }
}
