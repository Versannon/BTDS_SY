CPU Scheduling Algorithm:
    -Pre-emptive Priority Scheduling:
        1: SRTF (Shortest Remaining Time First)
        2: LRTF (Longest Remaining Time First)
        3: Round Robin.
        4: Priority Based.
    
    - Non-Pre-emptive Priority Scheduling:
        1: SJF (Shortest Job First)
        2: LJF (Longest Job First)
        3: FCFS (First Come First Serve)
        4: HRRN (Highest Response Ratio Next)
        5: Multilevel Queue.
    
        Theory-

        Formulas:
        1: Turn-Around Time = Completion Time - Arrival Time
        2: Waiting Time = Turn-Around Time - Burst Time

        FCFS(First Come First Serve):
            - Criteria = Arrival Time.
            - Mode = Non-Pre-emptive.

            Table:
            Process ID | Arrival Time | Burst Time | Completion Time | Turn-Around Time | Waiting Time
            P1         |   0          |     2      |        2        |        2         |       0 
            P2         |   1          |     2      |        4        |        3         |       1 
            P3         |   5          |     3      |        8        |        3         |       0 
            P4         |   6          |     4      |        12       |        6         |       2 


            Gantt Chart:
            | P1 | P2 | Idle | P3 | P4 |
            0    2    4      5    8    12

            Example:
            
            1.
            Table:
            Process ID | Arrival Time | Burst Time | Completion Time | Turn-Around Time | Waiting Time
            P1         |      2       |     2      |        13       |        11        |       9
            P2         |      5       |     6      |        19       |        14        |       8
            P3         |      0       |     4      |        4        |        4         |       0
            P4         |      0       |     7      |        11       |        11        |       4
            P5         |      7       |     4      |        23       |        16        |       12

            Gantt Chart:
            | P3 | P4 | P1 | P2 | P5 |
            0    4   11   13   19   23

            2.

            Table:
            Process ID | Arrival Time | Burst Time | Completion Time | Turn-Around Time | Waiting Time
            P1         |      2       |     2      |       4         |        2         |       0
            P2         |      0       |     1      |       1         |        1         |       0
            P3         |      2       |     3      |       7         |        5         |       2
            P4         |      3       |     5      |       12        |        9         |       4
            P5         |      4       |     5      |       17        |        13        |       8

            Gantt Chart:
            | P2 | IDLE | P1 | P3 | P4 | P5 |
            0    1      2    4    7    12   17
        
        Round Robin:
                - Criteria = Time Quantum.
                - Mode = Pre-emptive.

    
    Scheduling criteria Algorithms:

        1: Arrival time.
            - The time at which process enter the 'Ready' state.
        2: Burst time.
            - The time required by a process to get execute on CPU.
        3: Compile Time.
            - The time of which process compile its execution.
        4: Turn-around time.
            - (Completion time - arrival time)
        5: Waiting Time.
            - (Turn-around time - Burst time)
        6: Response Time.
            - (The time at which process gets the CPU for the first time - Arrival time)
        
        Example: Real life example.
            - Consider a restaurant scenario where customers (processes) arrive at different times and require varying amounts of time to be served (burst time). The restaurant (CPU scheduler) must decide the order in which to serve the customers based on their arrival times and service requirements. For instance, if a customer arrives and requires a short service time, they might be served before a customer who arrived earlier but requires a longer service time, depending on the scheduling algorithm used (e.g., SJF or FCFS). This illustrates how scheduling algorithms manage process execution based on various criteria to optimize performance and resource utilization.
        
    