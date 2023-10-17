#include <stdio.h>

int main()
{
    int c;
    int numBlankLines = 0; // Initialize as 1 because end of file will not have a new line character
    int numTabs = 0;
    int numSpaces = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            numSpaces++;
        }
        else if (c == '\t')
        {
            numTabs++;
        }
        else if (c == '\n')
        {
            numBlankLines++;
        }
    }
    printf("Lines : %d\nTabs : %d\nSpaces : %d\n", numBlankLines, numTabs, numSpaces);
}