//Code to tell if a student has passed or failed based on marks
#include <stdio.h>
int main()
{
    int mks;
    printf("Enter your Marks: ");
    scanf("%d", &mks);
    if(mks >= 40)
    {
        printf("You have passed\n");
    }
    else
    {
        printf("You have failed\n");
    }
    return 0;
}