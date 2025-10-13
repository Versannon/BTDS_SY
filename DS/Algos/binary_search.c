//Best Case = 0(1)
//Worst Case = 0(log n)

#include <stdio.h>
int main()
{
    int arr[100];
    int n;
    int left;
    int right;
    int mid;
    int key;
    int i;
    int found=0;

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

    printf("\nPlease enter a element you want to search in the array=");
    scanf("%d",&key);

    left=0;
    right=n-1;

    while(left<=right)
    {
        mid=(left+right)/2;

        if(key==arr[mid])
        {
            printf("Element found at index %d",mid);
            found=1;
            break;
        }

        else if(key<arr[mid])
        {
            right=mid-1;        
        }

        else
        {
            left=mid+1;
        }

    }

    if(found==0)
    {
        printf("Element not found in the array");
    }

    return 0;
}