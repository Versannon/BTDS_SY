//Code to print multiplication table of 5 using nested for loop
#include <stdio.h>
int main()
{
    // Loop through numbers 1 to 10
    for(int i = 1; i<=10; i++)
    {
        for (int j = 1; j<=i; j++)
        {
            printf("%d",  5*j);
        }
        printf(" \n");
    }
    return 0;
}