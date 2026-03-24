#include <stdio.h>

int main() {
    int n, i, j;

    // Step 1: Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Step 2: Declare arrays
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];

    // Step 3: Input arrival time and burst time
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
    }

    // Step 4: Sort processes based on Arrival Time
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {

                int temp;

                // Swap Arrival Time
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap Burst Time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap Process ID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Step 5: Calculate Completion Time for first process
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];
    rt[0] = wt[0];

    // Step 6: Calculate for remaining processes
    for(i = 1; i < n; i++) {

        if(ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];   // CPU idle case
        } else {
            ct[i] = ct[i-1] + bt[i]; // CPU busy case
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i];
    }

    // Step 7: Display Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}