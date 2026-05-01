#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;
    int at[10], bt[10], rt[10];
    int wt = 0, tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    // Input Arrival Time and Burst Time
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];  // remaining time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    // Round Robin Logic
    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time = time + rt[i];
                    rt[i] = 0;
                    remain--;

                    int completion = time;
                    int turnaround = completion - at[i];
                    int waiting = turnaround - bt[i];

                    wt += waiting;
                    tat += turnaround;

                    printf("P%d completed | WT=%d | TAT=%d\n", i+1, waiting, turnaround);
                }
                else {
                    rt[i] = rt[i] - tq;
                    time = time + tq;
                }
            }
        }
    }

    printf("\nAverage Waiting Time = %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time = %.2f", (float)tat/n);

    return 0;
}


