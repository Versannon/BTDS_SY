#include <stdio.h>
/*
 * ==============================================================================
 * VARIABLE GLOSSARY FOR ROUND ROBIN SCHEDULING
 * ==============================================================================
 * * General Variables:
 * n           : Total number of processes entered by the user.
 * i, j        : General-purpose loop iterator variables.
 * time        : Represents the current system clock / simulation timeline.
 * done        : Counter tracking how many processes have fully finished execution.
 * tq          : Time Quantum; the strict maximum CPU time a process gets in one turn.
 * * Arrays (Size 'n' based on user input):
 * at[]        : Arrival Time; when each process arrives in the system.
 * bt[]        : Burst Time; the total time each process needs from the CPU.
 * rem_bt[]    : Remaining Burst Time; tracks how much time a process still needs.
 * ct[]        : Completion Time; the exact 'time' clock value when a process finishes.
 * tat[]       : Turnaround Time; Total time spent in system (Completion Time - Arrival Time).
 * wt[]        : Waiting Time; Total time spent waiting in queue (Turnaround Time - Burst Time).
 * p[]         : Process ID (e.g., 1 for P1, 2 for P2) to keep track after sorting.
 * * Ready Queue Management Variables:
 * queue[]     : Array acting as a FIFO (First-In-First-Out) queue holding process indices.
 * front       : Points to the current process at the front of the queue to be executed.
 * rear        : Points to the next empty spot at the back of the queue for new arrivals.
 * in_queue[]  : Array acting as boolean flags (0=False, 1=True) to prevent double-queuing.
 * * Block-Level / Temporary Variables:
 * temp        : Used temporarily to swap values during the Bubble Sort phase.
 * idx         : The array index of the process currently picked from the queue to run.
 * time_to_run : The calculated time a process will run in the current turn 
 * (either the Time Quantum or whatever remaining burst time is left).
 * ==============================================================================
 */
int main() {
    int n, i, j, time = 0, done = 0, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int at[n], bt[n], rem_bt[n], ct[n], wt[n], tat[n], p[n];

    for (i = 0; i < n; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        
        p[i] = i + 1;
        rem_bt[i] = bt[i]; 
    }

    // 1. Sort by Arrival Time initially (Bubble Sort)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp;
                temp = at[j]; at[j] = at[j+1]; at[j+1] = temp;
                temp = bt[j]; bt[j] = bt[j+1]; bt[j+1] = temp;
                temp = rem_bt[j]; rem_bt[j] = rem_bt[j+1]; rem_bt[j+1] = temp;
                temp = p[j];  p[j] = p[j+1];   p[j+1] = temp;
            }
        }
    }

    // 2. Queue Setup for Round Robin
    int queue[100], front = 0, rear = 0;
    int in_queue[100] = {0}; 

    queue[rear++] = 0; 
    in_queue[0] = 1;
    time = at[0]; 

    // 3. Execution Loop
    while (done < n) {
        if (front == rear) {
            for (i = 0; i < n; i++) {
                if (rem_bt[i] > 0) {
                    time = at[i];
                    queue[rear++] = i;
                    in_queue[i] = 1;
                    break;
                }
            }
        }

        int idx = queue[front++];
        int time_to_run = (rem_bt[idx] < tq) ? rem_bt[idx] : tq;

        time += time_to_run;
        rem_bt[idx] -= time_to_run;

        for (i = 0; i < n; i++) {
            if (at[i] <= time && rem_bt[i] > 0 && !in_queue[i] && i != idx) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }
        if (rem_bt[idx] > 0) {
            queue[rear++] = idx;
        } else {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            done++;
        }
    }

    // 4. Output
    printf("\nID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}