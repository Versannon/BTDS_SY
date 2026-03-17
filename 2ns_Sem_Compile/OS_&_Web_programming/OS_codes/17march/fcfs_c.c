#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], id[n];

    // INPUT (user-defined, random order)
    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        id[i] = i + 1;
    }

    // SORT based on arrival time
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                int temp;

                // swap arrival time
                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // swap process id
                temp = id[j];
                id[j] = id[j + 1];
                id[j + 1] = temp;
            }
        }
    }

    // CALCULATION
    int time = 0;

    for (i = 0; i < n; i++)
    {
        if (time < at[i])
        {
            time = at[i];  // CPU idle
        }

        ct[i] = time + bt[i];
        wt[i] = time - at[i];
        tat[i] = ct[i] - at[i];

        time = ct[i];
    }

    // OUTPUT
    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n",
               id[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    return 0;
}