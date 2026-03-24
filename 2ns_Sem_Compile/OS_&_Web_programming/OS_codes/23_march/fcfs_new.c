//Shortest Job First Scheduling Algorithm
#include <stdio.h>
int main()
{
    int i,j,n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], id[n];

    //Input
    for(i=0; i<n; i++)
    {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        id[i] = i+1;
    }

    //Sorting

    for(i=0; i < n-1; i++)
    {
        
    }
}