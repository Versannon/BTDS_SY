#include <stdio.h>

int main() {
    int n, i, time = 0, done = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], pr[n], ct[n], wt[n], tat[n], p[n], finished[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\nArrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority (Lower # = Higher Priority): ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
        finished[i] = 0;
    }
    while (done < n) {
        int idx = -1, min_pr = 999999;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && !finished[i]) {
                if (pr[i] < min_pr) {
                    min_pr = pr[i];
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
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}
/* OUTPUT:
Enter number of processes: 3

Process 1
Arrival Time: 0
Burst Time: 5
Priority (Lower # = Higher Priority): 2

Process 2
Arrival Time: 1
Burst Time: 3
Priority (Lower # = Higher Priority): 1

Process 3
Arrival Time: 2
Burst Time: 1
Priority (Lower # = Higher Priority): 3

Process AT      BT      PR      CT      TAT     WT
P[1]    0       5       2       5       5       0
P[2]    1       3       1       8       7       4
P[3]    2       1       3       9       7       6
*/