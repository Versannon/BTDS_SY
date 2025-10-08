#include <stdio.h>
int main()
{
    int arr[100];
    int n;
    int i;
    int key;

    printf("How many elements do you want to enter in the array? \n");
    scanf("%d",&n);

    for(i=0;i<n;i++)                              //getting input from user
    {
        printf("Enter the element at index %d = ",i);
        scanf("%d",&arr[i]);
    }

    printf("The elements in the array are: \n");
    for(i=0;i<n;i++)                                 //printing the array
    {
        printf("%d ",arr[i]);
    }

    printf("\nPlease enter the element you want to search in the array=");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            printf("Element found at index %d",i);
            break;
        }
    }

    if(i==n)
    {
        printf("Element not found in the array");
    }
    return 0;
}