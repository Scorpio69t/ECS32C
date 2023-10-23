#include <stdio.h>

extern int between(char lowerBound, char upperBound, char target);
int main()
{
  printf("%d\n", between('C', 'R', 'M'));
  printf("%d\n", between('F', 'W', 'D'));
  printf("%d\n", between('T', 'Z', 'Y'));
  printf("%d\n", between('T', 'W', 'W'));
  printf("%d\n", between('t', 'Z', 'Y'));
  printf("%d\n", between('T', 'B', 'W'));
}