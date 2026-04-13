#include <stdio.h>

int main() {
    int n, i, j, time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Using Variable Length Arrays (VLAs) based on user input 'n'
    int at[n], bt[n], ct[n], wt[n], tat[n], p[n], finished[n];

    // INPUT (user-defined, random order)
    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        p[i] = i + 1;        // Using 'p' for Process ID to match the logic below
        finished[i] = 0;     // Explicitly initialize the finished tracking array to 0
    }

    // 1. Sort by Arrival Time initially
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;
                
                // Swap Arrival Time
                temp = at[j]; 
                at[j] = at[j+1]; 
                at[j+1] = temp;

                // Swap Burst Time
                temp = bt[j]; 
                bt[j] = bt[j+1]; 
                bt[j+1] = temp;

                // Swap Process ID
                temp = p[j];  
                p[j] = p[j+1];   
                p[j+1] = temp;
            }
        }
    }

    // 2. Execution Loop
    while (done < n) {
        int idx = -1, 
        min_bt = 999999;

        // Find shortest job that has arrived
        for (i = 0; i < n; i++) {
            if (at[i] <= time && !finished[i]) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += bt[idx];        // Move clock forward by Burst Time
            ct[idx] = time;         // Finish time
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            finished[idx] = 1;      // Mark process as complete
            done++;
        } else {
            time++;                 // Idle time: No one has arrived yet
        }
    }

    // 3. Output
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}