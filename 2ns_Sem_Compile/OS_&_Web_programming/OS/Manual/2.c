#include <stdio.h>

int main() {
    int n, i, j, time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], p[n], finished[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\nArrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        p[i] = i + 1;
        finished[i] = 0;
    }

    // Sort by Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;
                temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = p[j]; p[j] = p[j+1]; p[j+1] = temp;
            }
        }
    }

    while (done < n) {
        int idx = -1, min_bt = 999999;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && !finished[i]) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            finished[idx] = 1;
            done++;
        } else {
            time++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}

/* OUTPUT:
Enter number of processes: 3

Process 1
Arrival Time: 0
Burst Time: 8

Process 2
Arrival Time: 1
Burst Time: 4

Process 3
Arrival Time: 2
Burst Time: 2

Process AT      BT      CT      TAT     WT
P[1]    0       8       8       8       0
P[3]    2       2       10      8       6
P[2]    1       4       14      13      9
*/