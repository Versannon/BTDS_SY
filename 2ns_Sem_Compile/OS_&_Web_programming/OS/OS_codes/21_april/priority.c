#include <stdio.h>

int main() {
    int n, i, j;
    int bt[10], pr[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input Burst Time and Priority
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority for P%d: ", i+1);
        scanf("%d%d", &bt[i], &pr[i]);
    }

    // Sorting based on Priority (simple bubble sort)
    for(i = 0; i < n; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[i] > pr[j]) {
                // swap priority
                int temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Display Output
    printf("\nProcess\tBT\tPriority\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t\t%d\t%d\n", i+1, bt[i], pr[i], wt[i], tat[i]);
    }

    return 0;
}