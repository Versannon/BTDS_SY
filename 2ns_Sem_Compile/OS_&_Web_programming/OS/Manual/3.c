#include <stdio.h>

int main() {
    int n, i, time = 0, done = 0, quantum;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\nArrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Store remaining time
    }

    // Simplification: Assumes AT=0 for all to keep logic concise
    while (done < n) {
        int progress = 0;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                progress = 1;
                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    done++;
                }
            }
        }
        if (!progress) break; // Safety break
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}

/* OUTPUT:
Enter number of processes: 3
Enter time quantum: 2

Process 1
Arrival Time: 0
Burst Time: 5

Process 2
Arrival Time: 0
Burst Time: 4

Process 3
Arrival Time: 0
Burst Time: 3

Process AT      BT      CT      TAT     WT
P[1]    0       5       12      12      7
P[2]    0       4       11      11      7
P[3]    0       3       9       9       6
*/