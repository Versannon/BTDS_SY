#include <stdio.h>

int main() {
    int n, i;

    // Step 1: Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Step 2: Declare arrays. 
    // We add 'is_completed' to keep track of who is done.
    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n], rt[n];
    int is_completed[n]; 

    // Step 3: Input arrival time and burst time
    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time of P%d: ", i+1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i+1);
        scanf("%d", &bt[i]);
        
        is_completed[i] = 0; // 0 means false (not completed)
    }

    // Step 4 & 5 & 6: The SJF Time Loop
    int current_time = 0;
    int completed_count = 0;

    // Keep running until all processes are finished
    while (completed_count < n) {
        int short_index = -1;
        int min_burst = 9999999; // A very large number to start

        // Find the shortest job among the arrived processes
        for(i = 0; i < n; i++) {
            if (at[i] <= current_time && is_completed[i] == 0) {
                if (bt[i] < min_burst) {
                    min_burst = bt[i];
                    short_index = i;
                }
                // If two processes have the same burst time, pick the one that arrived first
                if (bt[i] == min_burst) {
                    if (at[i] < at[short_index]) {
                        short_index = i;
                    }
                }
            }
        }

        // If we found a process ready to execute
        if (short_index != -1) {
            // CPU processes the job
            current_time += bt[short_index]; 
            
            // Calculate metrics
            ct[short_index] = current_time;
            tat[short_index] = ct[short_index] - at[short_index];
            wt[short_index] = tat[short_index] - bt[short_index];
            rt[short_index] = wt[short_index]; // For non-preemptive, RT == WT

            // Mark as done
            is_completed[short_index] = 1; 
            completed_count++;
        } else {
            // If no process has arrived yet, the CPU sits idle
            current_time++;
        }
    }

    // Step 7: Display Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    return 0;
}