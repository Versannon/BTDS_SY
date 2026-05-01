#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], wt[n], tat[n], id[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\nArrival Time: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        id[i] = i + 1;
    }

    // Sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;
                temp = at[j]; at[j] = at[j + 1]; at[j + 1] = temp;
                temp = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = temp;
                temp = id[j]; id[j] = id[j + 1]; id[j + 1] = temp;
            }
        }
    }

    int time = 0;
    for (i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P[%d]\t%d\t%d\t%d\t%d\t%d\n", id[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    return 0;
}

/* OUTPUT:
Enter number of processes: 3

Process 1
Arrival Time: 0
Burst Time: 5

Process 2
Arrival Time: 1
Burst Time: 3

Process 3
Arrival Time: 2
Burst Time: 8

Process AT      BT      CT      TAT     WT
P[1]    0       5       5       5       0
P[2]    1       3       8       7       4
P[3]    2       8       16      14      6
*/