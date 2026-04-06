# Operating Systems — Unit 1 & Unit 2 (Up to FCFS)
## B.Tech Data Science Semester IV

---

## Table of Contents

1. [FCFS Level 3 Numerical Problems](#fcfs-level-3-numerical-problems)
2. [Theory Notes](#theory-notes)
3. [Question Paper Practice](#question-paper-practice)

---

# FCFS Level 3 Numerical Problems

## Problem 1: FCFS Scheduling with Even Arrival Times

### Given Data:

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 3         |
| P2      | 1            | 4         |
| P3      | 2            | 2         |
| P4      | 3            | 5         |

### Step-by-Step Solution:

**Step 1: Execution Order**
- Process P1 arrives at time 0 → Starts immediately
- Process P2 arrives at time 1 → Waits for P1 to complete
- Process P3 arrives at time 2 → Waits for P1 and P2
- Process P4 arrives at time 3 → Waits for P1, P2, and P3

**Step 2: Gantt Chart**

```
Time:  0   3       7        9        14
      |---|-------|---------|--------|
      | P1|   P2  |   P3   |   P4   |
      |---|-------|---------|--------|
```

**Step 3: Completion and Turnaround Times**

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time |
|---------|--------------|-----------|-----------------|-----------------|
| P1      | 0            | 3         | 3               | 3 - 0 = 3       |
| P2      | 1            | 4         | 7               | 7 - 1 = 6       |
| P3      | 2            | 2         | 9               | 9 - 2 = 7       |
| P4      | 3            | 5         | 14              | 14 - 3 = 11     |

**Step 4: Waiting Times**

| Process | Completion Time | Burst Time | Waiting Time |
|---------|-----------------|-----------|--------------|
| P1      | 0               | 3         | 0            |
| P2      | 3               | 4         | 2            |
| P3      | 7               | 2         | 5            |
| P4      | 9               | 5         | 6            |

**Step 5: Averages Calculation**

- **Average Waiting Time (AWT)** = (0 + 2 + 5 + 6) / 4 = 13 / 4 = **3.25 ms**
- **Average Turnaround Time (ATT)** = (3 + 6 + 7 + 11) / 4 = 27 / 4 = **6.75 ms**

---

## Problem 2: FCFS Scheduling with CPU Idle Time

### Given Data:

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 5         |
| P2      | 8            | 3         |
| P3      | 9            | 2         |
| P4      | 10           | 4         |

### Step-by-Step Solution:

**Step 1: Execution Order and Idle Period**
- Process P1 arrives at time 0 → Starts immediately (0 to 5)
- **CPU Idle from time 5 to 8** → No process arrives
- Process P2 arrives at time 8 → Starts at time 8
- Process P3 arrives at time 9 → Waits for P2
- Process P4 arrives at time 10 → Waits for P2 and P3

**Step 2: Gantt Chart**

```
Time:  0     5     8    11   13     17
      |-----|-----|---|----|----|------|
      | P1  |Idle | P2| P3 | P4|
      |-----|-----|---|----|----|------|
```

**Step 3: Completion and Turnaround Times**

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time |
|---------|--------------|-----------|-----------------|-----------------|
| P1      | 0            | 5         | 5               | 5 - 0 = 5       |
| P2      | 8            | 3         | 11              | 11 - 8 = 3      |
| P3      | 9            | 2         | 13              | 13 - 9 = 4      |
| P4      | 10           | 4         | 17              | 17 - 10 = 7     |

**Step 4: Waiting Times**

| Process | Arrival Time | Completion Time | Burst Time | Waiting Time |
|---------|--------------|-----------------|-----------|--------------|
| P1      | 0            | 5               | 5         | 0            |
| P2      | 8            | 11              | 3         | 0            |
| P3      | 9            | 13              | 2         | 2            |
| P4      | 10           | 17              | 4         | 3            |

**Step 5: Averages Calculation**

- **Average Waiting Time (AWT)** = (0 + 0 + 2 + 3) / 4 = 5 / 4 = **1.25 ms**
- **Average Turnaround Time (ATT)** = (5 + 3 + 4 + 7) / 4 = 19 / 4 = **4.75 ms**

**Key Observation:** CPU remains idle for 3 time units (from 5 to 8), resulting in poor resource utilization and higher average waiting time.

---

# Theory Notes

## 1. Definition of Operating System

An **Operating System (OS)** is a system software that acts as an intermediary between a user and the computer hardware. It manages hardware resources and provides common services for application software. The OS is responsible for:

- Allocating and deallocating resources
- Scheduling processes
- Managing memory
- Handling input/output operations
- Providing a user interface

---

## 2. Functions of Operating System

The main functions of an OS include:

1. **Resource Management** - Manages hardware resources like CPU, memory, disk, and I/O devices
2. **Process Management** - Controls process creation, scheduling, and termination
3. **Memory Management** - Allocates and deallocates memory to processes
4. **File Management** - Creates, deletes, and manages files and directories
5. **Device Management** - Controls peripheral devices and I/O operations
6. **Security and Protection** - Protects user data and system resources
7. **User Interface** - Provides mechanisms for user interaction (CLI/GUI)
8. **Concurrent Execution** - Allows multiple programs to run simultaneously

---

## 3. Operating System Structures

### 3.1 Simple Batch System

**Definition:** A batch system is where jobs are grouped together and executed one by one without user interaction.

**Characteristics:**
- Jobs are collected and executed as a batch
- No direct user interaction once job starts
- Jobs are executed in the order they were submitted
- Uses card readers or tape as input device
- Suitable for offline processing

**Advantages:**
- High throughput
- No user waiting at terminal
- Suitable for bulk processing

**Disadvantages:**
- No interactivity
- Poor resource utilization
- Long turnaround time
- Difficult to debug

---

### 3.2 Multiprogrammed System

**Definition:** A system where multiple programs are loaded into memory simultaneously, and the CPU executes them in an interleaved manner.

**Characteristics:**
- Multiple programs reside in memory at the same time
- CPU switches between programs
- Increases CPU utilization
- Requires sophisticated scheduling algorithms
- Uses interrupts for switching

**Advantages:**
- Better CPU utilization
- Faster response time
- Increased throughput
- Resource sharing

**Disadvantages:**
- Complex memory management
- Need for synchronization mechanisms
- Requires sophisticated hardware support
- Difficult to debug and manage

---

## 4. Main System Components of OS

The main components of an OS are:

| Component | Function |
|-----------|----------|
| **Process Manager** | Handles process creation, scheduling, and termination |
| **Memory Manager** | Manages memory allocation and deallocation |
| **File Manager** | Manages files and directory structures |
| **Device Manager** | Controls I/O devices and peripheral management |
| **Command Interpreter/Shell** | Interprets user commands |
| **System Libraries** | Provides standard functions and utilities |
| **Scheduler** | Assigns CPU time to processes |
| **Dispatcher** | Switches context between processes |

---

## 5. Operating System Services

An OS provides the following services to users and applications:

1. **Program Execution** - Loads and executes programs
2. **I/O Operations** - Manages input and output devices
3. **File System Manipulation** - Creates, reads, writes, deletes files
4. **Communications** - Enables inter-process communication
5. **Error Handling** - Detects and responds to errors
6. **Resource Allocation** - Allocates CPU, memory, devices to processes
7. **Accounting and Statistics** - Tracks resource usage
8. **Protection and Security** - Protects system and user data

---

## 6. System Calls

**Definition:** System calls are the interface between user programs and the operating system kernel. They provide a way for user-level processes to request services from the OS.

### 6.1 Types of System Calls

1. **Process Control System Calls**
   - `fork()` - Create a new process
   - `exec()` - Replace current process with a new program
   - `exit()` - Terminate a process
   - `wait()` - Wait for child process termination

2. **File Management System Calls**
   - `open()` - Open a file
   - `close()` - Close a file
   - `read()` - Read from file
   - `write()` - Write to file
   - `delete()` - Delete a file

3. **Device Management System Calls**
   - `read()` - Read from device
   - `write()` - Write to device
   - `ioctl()` - Control I/O device

4. **Information Maintenance System Calls**
   - `getpid()` - Get process ID
   - `getuid()` - Get user ID
   - `time()` - Get current time
   - `stat()` - Get file status

5. **Communication System Calls**
   - `socket()` - Create communication socket
   - `send()` - Send message
   - `recv()` - Receive message
   - `connect()` - Connect to remote process

---

## 7. Process Concept

### 7.1 Definition

A **process** is a program in execution. It represents a unit of work or a job that the OS schedules and executes.

### 7.2 Process Structure

A process consists of:

- **Text Section** - Program code
- **Data Section** - Global variables
- **Heap** - Dynamically allocated memory
- **Stack** - Temporary data, function parameters, return addresses
- **Process Control Block (PCB)** - Metadata about the process

### 7.3 Process Identification

Each process has:
- **Process ID (PID)** - Unique identifier
- **Parent Process ID (PPID)** - ID of parent process
- **User ID (UID)** - User who created the process

---

## 8. Process States

A process transitions through the following states:

```
     ┌──────────────┐
     │     NEW      │
     └──────┬───────┘
            │
            │ Admitted
            ▼
     ┌──────────────┐
     │    READY     │◄────────┐
     └──────┬───────┘         │
            │                 │
            │ Scheduled       │
            ▼                 │
     ┌──────────────┐         │
     │   RUNNING    ├─────────┤
     └──────┬───────┘         │
            │                 │
            │ Interrupted     │
            │ or Preempted    │
            │                 │
     ┌──────┴───────┐         │
     │     WAITING  ├─────────┘
     └──────┬───────┘
            │
            │ I/O Completion
            ▼
     ┌──────────────┐
     │  TERMINATED  │
     └──────────────┘
```

### State Descriptions:

- **NEW** - Process is being created
- **READY** - Process is ready to run but waiting for CPU allocation
- **RUNNING** - Process is executing on CPU
- **WAITING** - Process is waiting for I/O event or other resource
- **TERMINATED** - Process has completed execution

---

## 9. Operations on Processes

### 9.1 Process Creation

Processes are created through:
- User command submission
- Batch job initiation
- OS initialization
- User request for service

The parent process uses `fork()` to create a child process.

### 9.2 Process Termination

A process terminates when:
- Normal completion occurs
- Fatal error is encountered
- Parent process terminates
- User request is made

---

## 10. Cooperating Processes and Advantages

### 10.1 Definition

**Cooperating processes** are processes that can affect or be affected by other processes executing in the system.

### 10.2 Advantages of Cooperating Processes

1. **Information Sharing** - Processes can share data and information
2. **Computation Speedup** - Multiple processes can work on a task in parallel
3. **Modularity** - System design can be modular
4. **Convenience** - User can work on multiple tasks simultaneously

### 10.3 Requirements for Cooperation

- **Inter-Process Communication (IPC)** mechanisms
- **Synchronization** to coordinate activities
- **Mutual Exclusion** to prevent conflicts

---

## 11. Threads and Advantages

### 11.1 Definition

A **thread** is a lightweight process, also called a "process within a process." It is a unit of execution within a process.

### 11.2 Characteristics

- Share same address space with other threads of the same process
- Have independent program counter and stack
- Can be created and destroyed more quickly than processes
- Require less overhead than processes

### 11.3 Advantages of Threads

1. **Responsiveness** - User interface remains responsive
2. **Resource Sharing** - Efficient sharing of resources
3. **Economy** - Thread creation and switching is faster
4. **Scalability** - Better utilization of multiprocessor systems
5. **Concurrency** - Multiple operations can occur simultaneously

---

## 12. CPU Scheduling

### 12.1 Definition

**CPU Scheduling** is the process of selecting which process should be executed by the CPU at any given time.

### 12.2 Scheduling Objectives

- Maximize CPU utilization
- Maximize throughput (number of processes completed per unit time)
- Minimize turnaround time (total time from submission to completion)
- Minimize waiting time (time spent waiting in ready queue)
- Minimize response time (time until first response is produced)
- Ensure fairness among processes

---

## 13. Scheduling Criteria

The performance of a scheduling algorithm is evaluated using the following criteria:

### 13.1 Utilization

The percentage of time the CPU is busy executing processes.

- Target: Keep CPU as busy as possible (90-100%)
- Formula: Utilization = CPU Busy Time / Total Time

### 13.2 Throughput

The number of processes that complete execution per unit time.

- Measured as processes per unit time
- Higher throughput is desirable
- Formula: Throughput = Number of Processes / Total Time

### 13.3 Turnaround Time

The total time taken from the moment a process is submitted to the moment it completes execution.

- Formula: Turnaround Time = Completion Time - Arrival Time
- Lower turnaround time is desirable
- Includes waiting and execution time

### 13.4 Waiting Time

The total time a process spends waiting in the ready queue.

- Formula: Waiting Time = Turnaround Time - Burst Time
- Lower waiting time is desirable
- Most important criterion for user perspective

### 13.5 Response Time

The time taken from process submission to the first response output.

- Important for interactive systems
- Lower response time means better user experience

---

## 14. First Come First Serve (FCFS) Scheduling

### 14.1 Definition

**FCFS (First Come First Serve)**, also known as **FIFO (First In First Out)**, is the simplest CPU scheduling algorithm. Processes are executed in the order they arrive in the ready queue.

### 14.2 How FCFS Works

1. Processes are placed in a queue in the order of arrival
2. The first process in the queue gets the CPU
3. The process runs until it completes (non-preemptive)
4. The next process then gets the CPU

### 14.3 Implementation

FCFS can be implemented using a simple FIFO queue:

```
Ready Queue: [P1, P2, P3, P4]
              ↑
         Process gets CPU here

After P1 completes:
Ready Queue: [P2, P3, P4]
              ↑
         P2 gets CPU next
```

### 14.4 Characteristics of FCFS

- **Simple Implementation** - Very easy to understand and implement
- **Non-preemptive** - Once a process gets CPU, it runs until completion
- **Fair** - Every process will eventually get CPU time
- **Deterministic** - Execution order is predetermined
- **No Starvation** - Every process will eventually get CPU time

### 14.5 Advantages of FCFS

1. **Simple to Understand and Implement** - No complex data structures required
2. **No Starvation** - Every process will get CPU time eventually
3. **Fair** - Processes are served in the order they arrive
4. **Minimal Overhead** - Very little computation required to select next process
5. **Suitable for Batch Systems** - Works well for non-interactive batch jobs

### 14.6 Disadvantages of FCFS

1. **Convoy Effect** - Short processes can get delayed behind long processes
2. **Poor Average Waiting Time** - Can be very high if one long process arrives first
3. **Not Suitable for Interactive Systems** - Users have to wait for long processes
4. **Cannot Prioritize Important Processes** - All processes are treated equally
5. **Poor CPU Utilization** - Can leave CPU idle if processes have I/O operations
6. **Long Turnaround Time** - Total time to complete all processes can be high

### 14.7 Example: Convoy Effect

Consider processes with burst times: P1=20ms, P2=1ms, P3=1ms

```
FCFS Scheduling:
Time:  0         20  21  22
      |----------|--|--|
      |    P1    |P2|P3|

Average Waiting Time = (0 + 20 + 21) / 3 = 13.67 ms
Average Turnaround Time = (20 + 21 + 22) / 3 = 21 ms

If rearranged (not FCFS):
Time:  0  1  2      22
      |--|--|--------|
      |P2|P3|   P1   |

Average Waiting Time = (0 + 1 + 2) / 3 = 1 ms
Average Turnaround Time = (1 + 2 + 22) / 3 = 8.33 ms
```

---

# Question Paper Practice

## Question Paper 1

**Total Marks: 25** | **Time: 1 Hour**

**Question 1 (5 marks):** Define Operating System and explain its main functions in detail.

**Question 2 (5 marks):** Differentiate between Simple Batch System and Multiprogrammed System with advantages and disadvantages.

**Question 3 (5 marks):** Explain the main system components of an Operating System and their functions.

**Question 4 (5 marks):** What are system calls? Explain different types of system calls with examples.

**Question 5 (5 marks):** Explain the concept of processes and the different states a process can go through during its execution.

---

## Question Paper 2

**Total Marks: 25** | **Time: 1 Hour**

**Question 1 (5 marks):** Define a thread and explain the advantages of using threads in an operating system.

**Question 2 (5 marks):** What are cooperating processes? Explain the advantages of process cooperation and mechanisms required for it.

**Question 3 (5 marks):** Explain the concept of CPU scheduling and list the scheduling criteria with detailed explanations.

**Question 4 (5 marks):** What is FCFS scheduling? Explain its characteristics, advantages, and disadvantages.

**Question 5 (5 marks):** Solve the following FCFS scheduling problem:

```
Process | Arrival Time | Burst Time
--------|--------------|------------
P1      | 0            | 4
P2      | 1            | 3
P3      | 2            | 1
```

Calculate: Gantt chart, Waiting times, Turnaround times, Average Waiting Time, Average Turnaround Time.

---

## Question Paper 3

**Total Marks: 25** | **Time: 1 Hour**

**Question 1 (5 marks):** Explain the process state diagram with all possible state transitions and explain what triggers each transition.

**Question 2 (5 marks):** What are operating system services? Explain any five important OS services and their importance.

**Question 3 (5 marks):** Define process control block (PCB) and explain the information stored in it. Why is PCB important?

**Question 4 (5 marks):** Explain the concept of multiprogramming and its advantages in modern operating systems.

**Question 5 (5 marks):** Solve the following FCFS scheduling problem with CPU idle time:

```
Process | Arrival Time | Burst Time
--------|--------------|------------
P1      | 0            | 3
P2      | 5            | 2
P3      | 6            | 4
P4      | 7            | 1
```

Calculate: Gantt chart, Waiting times, Turnaround times, Average Waiting Time, Average Turnaround Time.

---

## Question Paper 4

**Total Marks: 25** | **Time: 1 Hour**

**Question 1 (5 marks):** Explain the difference between a process and a program. How does an operating system manage processes?

**Question 2 (5 marks):** What is time-sharing system? Explain how it provides fairness and responsiveness to multiple users.

**Question 3 (5 marks):** What is a distributed operating system? Explain its advantages and disadvantages.

**Question 4 (5 marks):** Discuss the "Convoy Effect" in FCFS scheduling. Why is this a significant disadvantage of FCFS?

**Question 5 (5 marks):** Solve the following FCFS scheduling problem:

```
Process | Arrival Time | Burst Time
--------|--------------|------------
P1      | 0            | 8
P2      | 2            | 4
P3      | 4            | 2
P4      | 5            | 3
```

Calculate: Gantt chart, Waiting times, Turnaround times, Average Waiting Time, Average Turnaround Time, CPU Utilization.

---

## Question Paper 5

**Total Marks: 25** | **Time: 1 Hour**

**Question 1 (5 marks):** Explain the operations on processes: process creation and process termination. What are the events that trigger each?

**Question 2 (5 marks):** Differentiate between user mode and kernel mode. Why is this distinction important for operating system security?

**Question 3 (5 marks):** Explain system calls with examples. How do system calls provide the interface between user programs and the operating system?

**Question 4 (5 marks):** Compare FCFS scheduling with other scheduling criteria in terms of average waiting time and CPU utilization.

**Question 5 (5 marks):** Solve the following FCFS scheduling problem:

```
Process | Arrival Time | Burst Time
--------|--------------|------------
P1      | 0            | 5
P2      | 3            | 2
P3      | 6            | 3
P4      | 8            | 1
P5      | 10           | 4
```

Calculate: Gantt chart, Waiting times, Turnaround times, Average Waiting Time, Average Turnaround Time.

---

## Study Tips

1. **Review regularly** - Go through the theory notes multiple times
2. **Practice problems** - Solve all FCFS numerical problems multiple times
3. **Create summaries** - Make bullet-point summaries of each topic
4. **Understand concepts** - Don't just memorize; understand the "why" behind each concept
5. **Practice papers** - Solve all five question papers under exam conditions
6. **Group study** - Discuss concepts with classmates to clarify doubts
7. **Focus areas** - Pay special attention to FCFS scheduling and process states

---

# Answer Key

## Question Paper 1 - Answers

### Answer 1: Definition and Functions of Operating System

**Definition:** An Operating System is system software that acts as an intermediary between users and computer hardware, managing all hardware resources and providing services to application programs.

**Main Functions:**
1. **Resource Management** - The OS allocates and manages hardware resources (CPU, memory, disk, I/O devices) among multiple processes
2. **Process Management** - Controls creation, scheduling, execution, and termination of processes
3. **Memory Management** - Allocates memory to processes, manages virtual memory, and prevents memory conflicts
4. **File Management** - Maintains file systems, handles file creation, deletion, reading, and writing
5. **Device Management** - Controls peripheral devices (printers, scanners, etc.) and manages I/O operations
6. **Security and Protection** - Provides user authentication, access control, and data protection
7. **User Interface** - Offers both command-line (CLI) and graphical (GUI) interfaces for user interaction
8. **Concurrent Execution** - Enables multiple programs to run simultaneously without interference

The OS acts as a resource manager ensuring efficient and fair allocation of resources among competing processes.

---

### Answer 2: Simple Batch System vs Multiprogrammed System

**Simple Batch System:**
- Jobs are collected and submitted in batches
- Executed sequentially without user interaction
- Uses card readers or tape drives for input
- Non-interactive and suitable for bulk processing
- **Advantages:** High throughput, no user waiting time
- **Disadvantages:** Poor resource utilization, long turnaround time, difficult to debug, no interactivity

**Multiprogrammed System:**
- Multiple programs reside in memory simultaneously
- CPU switches between programs using scheduling algorithms
- Interactive and handles I/O operations efficiently
- Uses interrupts for context switching
- **Advantages:** Better CPU utilization, faster response, increased throughput, efficient resource sharing
- **Disadvantages:** Complex memory management, need for synchronization, requires sophisticated hardware support

**Key Difference:** Batch systems execute jobs sequentially, while multiprogrammed systems execute multiple jobs concurrently using context switching.

---

### Answer 3: Main System Components of Operating System

The main components and their functions are:

1. **Process Manager** - Creates, schedules, and terminates processes; manages process scheduling and context switching
2. **Memory Manager** - Allocates memory to processes, manages virtual memory, and ensures memory protection
3. **File Manager** - Manages file systems, handles file operations (create, read, write, delete)
4. **Device Manager** - Controls I/O devices and manages peripheral device operations
5. **Command Interpreter/Shell** - Interprets user commands and executes them
6. **System Libraries** - Provides standard functions and APIs for application programs to use OS services
7. **Scheduler** - Determines which process should execute next based on scheduling algorithms
8. **Dispatcher** - Performs context switching and transfers CPU control to selected process

These components work together to provide a complete operating environment for executing programs and managing hardware resources.

---

### Answer 4: System Calls and Their Types

**Definition:** System calls are request mechanisms that allow user programs to request services from the operating system kernel.

**Types of System Calls:**

1. **Process Control System Calls**
   - `fork()` - Creates a new child process
   - `exec()` - Replaces current process with a new program
   - `exit()` - Terminates the process
   - `wait()` - Waits for child process termination

2. **File Management System Calls**
   - `open()` - Opens a file
   - `close()` - Closes a file
   - `read()` - Reads data from file
   - `write()` - Writes data to file

3. **Device Management System Calls**
   - `read()` - Reads from device
   - `write()` - Writes to device
   - `ioctl()` - Issues control commands to devices

4. **Information Maintenance System Calls**
   - `getpid()` - Returns process ID
   - `time()` - Returns current time
   - `stat()` - Returns file status information

5. **Communication System Calls**
   - `socket()` - Creates communication socket
   - `send()` - Sends message to another process
   - `recv()` - Receives message from another process

---

### Answer 5: Process States and Execution

**Process States:**

1. **NEW** - Process is being created and not yet ready for execution
2. **READY** - Process is prepared and waiting for CPU allocation
3. **RUNNING** - Process is currently executing on the CPU
4. **WAITING** - Process is blocked waiting for I/O completion or other resources
5. **TERMINATED** - Process has completed execution

**State Transitions:**
- NEW → READY: Once process is created, it moves to ready state
- READY → RUNNING: Scheduler selects and dispatcher allocates CPU
- RUNNING → READY: Process is interrupted or preempted
- RUNNING → WAITING: Process requests I/O or waits for resource
- WAITING → READY: I/O completion or resource becomes available
- RUNNING → TERMINATED: Process completes or is forcefully terminated

Understanding these states is crucial for process management and scheduling in operating systems.

---

## Question Paper 2 - Answers

### Answer 1: Threads and Their Advantages

**Definition:** A thread is a lightweight process or a unit of execution within a process. Multiple threads can exist within a single process and share the same address space but have independent execution flows.

**Advantages of Threads:**

1. **Responsiveness** - User interface remains responsive even while performing long operations in background threads
2. **Resource Sharing** - Threads share the same memory space and resources, reducing overhead compared to multiple processes
3. **Economy** - Thread creation and context switching is much faster than creating new processes
4. **Scalability** - Threads can effectively utilize multiprocessor systems for true parallel execution
5. **Concurrency** - Multiple operations can proceed simultaneously within the same process
6. **Better Performance** - Reduced memory usage and faster inter-thread communication compared to inter-process communication

Threads are particularly useful for building responsive, interactive applications that need to perform multiple concurrent operations.

---

### Answer 2: Cooperating Processes

**Definition:** Cooperating processes are processes that can affect or be affected by other processes in the system. They share data and communicate with each other.

**Advantages of Process Cooperation:**

1. **Information Sharing** - Processes can share data and exchange information through shared memory or message passing
2. **Computation Speedup** - Multiple processes can work on different parts of a task in parallel, reducing total execution time
3. **Modularity** - System design becomes modular where different processes handle different functions
4. **Convenience** - Users can perform multiple independent tasks simultaneously

**Requirements for Cooperation:**
- **Inter-Process Communication (IPC)** - Mechanisms like pipes, sockets, shared memory for data exchange
- **Synchronization** - Coordination mechanisms to ensure processes work together correctly
- **Mutual Exclusion** - Ensures only one process accesses shared resources at a time to prevent data corruption

Process cooperation is essential for building complex systems where multiple components need to work together.

---

### Answer 3: CPU Scheduling and Scheduling Criteria

**CPU Scheduling:** It is the process of selecting which process should execute next on the CPU to maximize system performance.

**Scheduling Criteria:**

1. **CPU Utilization** - Percentage of time CPU is executing processes (target: 90-100%)
   - Formula: Utilization = CPU Busy Time / Total Time

2. **Throughput** - Number of processes completed per unit time
   - Higher throughput is desirable
   - Formula: Throughput = Number of Processes / Total Time

3. **Turnaround Time** - Total time from process submission to completion
   - Includes waiting and execution time
   - Formula: Turnaround Time = Completion Time - Arrival Time
   - Lower is better

4. **Waiting Time** - Time process spends waiting in ready queue
   - Formula: Waiting Time = Turnaround Time - Burst Time
   - Most critical from user perspective

5. **Response Time** - Time from submission to first response output
   - Critical for interactive systems

Scheduling algorithms are evaluated based on how well they optimize these criteria.

---

### Answer 4: FCFS Scheduling

**Definition:** First Come First Serve (FCFS) is the simplest CPU scheduling algorithm where processes are executed in the order they arrive in the ready queue.

**Characteristics:**
- Simple and easy to implement
- Non-preemptive (process runs until completion)
- Fair treatment to all processes
- Deterministic execution order
- No starvation (every process eventually gets CPU)

**Advantages:**
1. Very simple to understand and implement
2. No overhead for decision making
3. Every process gets fair CPU time
4. No process is starved
5. Suitable for batch systems

**Disadvantages:**
1. **Convoy Effect** - Short processes wait behind long processes
2. Poor average waiting time if long process arrives first
3. Unsuitable for interactive systems (users must wait)
4. Cannot prioritize important processes
5. Low CPU utilization with I/O bound processes
6. High turnaround time

FCFS is rarely used in modern systems due to poor performance with mixed workloads.

---

### Answer 5: FCFS Scheduling Problem Solution

**Given Data:**

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 4         |
| P2      | 1            | 3         |
| P3      | 2            | 1         |

**Gantt Chart:**

```
Time:  0   4       7    8
      |---|-------|---|
      | P1|   P2  |P3|
      |---|-------|---|
```

**Completion Times:**
- P1: 4
- P2: 7
- P3: 8

**Waiting Times:**
- P1: 0 - 0 = 0 ms
- P2: 4 - 1 = 3 ms
- P3: 7 - 2 = 5 ms

**Turnaround Times:**
- P1: 4 - 0 = 4 ms
- P2: 7 - 1 = 6 ms
- P3: 8 - 2 = 6 ms

**Averages:**
- Average Waiting Time = (0 + 3 + 5) / 3 = 8/3 = **2.67 ms**
- Average Turnaround Time = (4 + 6 + 6) / 3 = 16/3 = **5.33 ms**

---

## Question Paper 3 - Answers

### Answer 1: Process State Diagram and Transitions

**Process State Diagram:**

The five main states are NEW, READY, RUNNING, WAITING, and TERMINATED with the following transitions:

**State Transitions:**

1. **NEW → READY** - Triggered by: Process creation completion, OS allocates memory and resources
2. **READY → RUNNING** - Triggered by: Scheduler selects process, dispatcher allocates CPU
3. **RUNNING → READY** - Triggered by: Time quantum expires (in preemptive systems), process is preempted
4. **RUNNING → WAITING** - Triggered by: Process requests I/O operation, waits for resource, or waits for event
5. **WAITING → READY** - Triggered by: I/O operation completion, resource becomes available, event occurs
6. **RUNNING → TERMINATED** - Triggered by: Process completes execution, encounters fatal error, or is killed
7. **WAITING → TERMINATED** - Triggered by: Parent process terminates while child is waiting

Each transition represents a change in process status due to specific events in the system.

---

### Answer 2: Operating System Services

**Definition:** OS services are functionalities provided by the operating system to user programs and applications.

**Five Important OS Services:**

1. **Program Execution** - Loads programs into memory and executes them. Provides the runtime environment for applications without concerning the user with hardware details.

2. **I/O Operations** - Manages input/output through devices (keyboard, mouse, printer, disk). Users don't directly interact with hardware; OS handles all device communication.

3. **File System Manipulation** - Creates, reads, writes, and deletes files. Manages directory structures and file organization on storage devices.

4. **Communications** - Enables processes to communicate with each other through pipes, sockets, or shared memory. Critical for concurrent and distributed systems.

5. **Resource Allocation** - Distributes CPU time, memory, and I/O devices among competing processes. Ensures fair and efficient resource utilization.

6. **Error Handling** - Detects errors and responds appropriately without crashing the system. Protects system stability.

7. **Security and Protection** - Prevents unauthorized access, enforces access controls, and protects user data and system resources.

These services form the foundation of the OS functionality.

---

### Answer 3: Process Control Block (PCB)

**Definition:** Process Control Block (PCB) is a data structure maintained by the operating system that contains all information about a process.

**Information Stored in PCB:**

1. **Process Identification**
   - Process ID (PID)
   - Parent Process ID (PPID)
   - User ID (UID)
   - Group ID (GID)

2. **Process State** - Current state (NEW, READY, RUNNING, WAITING, TERMINATED)

3. **Program Counter** - Memory address of next instruction to execute

4. **CPU Registers** - Values of CPU registers (for context switching)

5. **Memory Management Information**
   - Base address of process memory
   - Limit register
   - Page table or segment table pointer

6. **I/O Status Information** - List of I/O devices allocated to process, open files, etc.

7. **Scheduling Information**
   - Process priority
   - Scheduling queue pointers
   - Time quantum

8. **Accounting Information**
   - CPU time used
   - Clock time used
   - Memory used
   - Disk I/O

**Importance of PCB:**
- Essential for context switching and process management
- Allows OS to save and restore process state
- Enables multitasking and multiprogramming
- Critical for process synchronization and scheduling
- Maintains complete process information for management

---

### Answer 4: Multiprogramming

**Definition:** Multiprogramming is a technique where multiple programs are loaded into memory simultaneously, and the CPU switches between them to execute their instructions.

**How Multiprogramming Works:**
- Multiple programs reside in main memory at the same time
- CPU executes instructions from one program, then switches to another
- When one program waits for I/O, CPU executes another program
- Uses interrupts to manage context switching

**Advantages:**

1. **Increased CPU Utilization** - CPU never remains idle; while one process waits for I/O, another can execute
2. **Reduced Turnaround Time** - Multiple jobs progress simultaneously instead of sequentially
3. **Increased Throughput** - More processes can be completed in given time period
4. **Better Resource Utilization** - All hardware resources are utilized effectively
5. **Cost Effectiveness** - Expensive hardware is used more efficiently
6. **Faster Response** - Interactive programs get faster responses
7. **More Fair** - All processes get CPU time rather than one hogging the CPU

Multiprogramming is fundamental to modern operating systems and enables efficient utilization of system resources.

---

### Answer 5: FCFS Scheduling Problem with CPU Idle Time

**Given Data:**

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 3         |
| P2      | 5            | 2         |
| P3      | 6            | 4         |
| P4      | 7            | 1         |

**Gantt Chart:**

```
Time:  0   3   5   7   11  12
      |---|---|---|---|----|--
      | P1|Idle|P2 |P3 |P4|
      |---|---|---|---|----|--
```

**Completion Times:**
- P1: 3
- P2: 7
- P3: 11
- P4: 12

**Waiting Times:**
- P1: 0 - 0 = 0 ms
- P2: 5 - 5 = 0 ms
- P3: 7 - 6 = 1 ms
- P4: 11 - 7 = 4 ms

**Turnaround Times:**
- P1: 3 - 0 = 3 ms
- P2: 7 - 5 = 2 ms
- P3: 11 - 6 = 5 ms
- P4: 12 - 7 = 5 ms

**Averages:**
- Average Waiting Time = (0 + 0 + 1 + 4) / 4 = 5/4 = **1.25 ms**
- Average Turnaround Time = (3 + 2 + 5 + 5) / 4 = 15/4 = **3.75 ms**

**CPU Idle Time:** 2 time units (from time 3 to 5)

**CPU Utilization:** (10 / 12) × 100 = **83.33%**

---

## Question Paper 4 - Answers

### Answer 1: Process vs Program

**Program:**
- A program is a set of instructions written in a programming language
- It is a static entity stored on disk
- Cannot perform any action by itself
- Same program can be executed multiple times
- Does not have PCB or process state

**Process:**
- A process is a program in execution
- Dynamic entity that exists in memory and CPU
- Can perform actions and interact with system
- Multiple processes can be instances of the same program
- Has PCB containing process-specific information
- Has states: NEW, READY, RUNNING, WAITING, TERMINATED

**How OS Manages Processes:**

1. **Process Creation** - OS creates PCB, allocates memory, sets up resources
2. **Process Scheduling** - OS determines which process executes next
3. **Context Switching** - OS saves state of running process, loads state of next process
4. **Resource Allocation** - OS allocates CPU, memory, and I/O to processes
5. **Synchronization** - OS ensures processes don't interfere with each other
6. **Process Termination** - OS deallocates resources and removes PCB

---

### Answer 2: Time-Sharing System

**Definition:** A time-sharing system is a multiprogrammed system where each process gets a small slice of CPU time (time quantum), after which CPU is switched to the next process.

**How Time-Sharing Provides Fairness:**

1. **Equal Time Quantum** - Each process receives equal CPU time, ensuring no process is starved
2. **Round Robin Scheduling** - Processes are treated fairly in circular order
3. **Preemptive Scheduling** - No process monopolizes CPU; all get regular turns
4. **Fair Resource Allocation** - CPU time is distributed equitably among all processes

**How Time-Sharing Provides Responsiveness:**

1. **Quick Response Time** - Each user feels like they have dedicated machine because of frequent context switching
2. **Interactive Feel** - Multiple users can interact with system simultaneously
3. **No Long Waits** - Users don't wait long for CPU even in busy system
4. **Concurrent Operations** - Multiple tasks appear to run simultaneously from user perspective
5. **Real-time Interactivity** - System responds quickly to user inputs

Time-sharing revolutionized computing by enabling multiple users to use one computer simultaneously with apparent responsiveness.

---

### Answer 3: Distributed Operating System

**Definition:** A distributed operating system is an OS that manages a group of independent computers connected by a network and provides them with a unified interface as if they were a single system.

**Advantages:**
1. **Resource Sharing** - Resources (printers, disk space, data) can be shared across network
2. **Increased Reliability** - If one computer fails, others continue working
3. **Better Performance** - Load can be distributed across multiple computers
4. **Scalability** - Can easily add more computers to increase capacity
5. **Cost Effectiveness** - Can use cheaper individual computers instead of one large computer
6. **Concurrency** - Multiple computers can work on different parts of large problem simultaneously

**Disadvantages:**
1. **Complexity** - Very complex to design and implement
2. **Network Dependency** - Relies on network communication which can be slow and unreliable
3. **Security Issues** - Distributed systems are more vulnerable to security attacks
4. **Difficult Debugging** - Hard to debug problems in geographically distributed systems
5. **Higher Cost** - Initial setup and maintenance is expensive
6. **Consistency Issues** - Maintaining data consistency across multiple computers is challenging

---

### Answer 4: Convoy Effect in FCFS

**Definition:** The convoy effect is a phenomenon in FCFS scheduling where short processes get delayed behind a long process, resulting in poor average waiting time.

**Example:**

```
Consider processes: P1 (20ms), P2 (1ms), P3 (1ms)

FCFS Scheduling:
Time: 0          20  21  22
     |----------|--|--|
     |    P1    |P2|P3|

P1's waiting time = 0 ms
P2's waiting time = 20 ms
P3's waiting time = 21 ms
Average Waiting Time = (0 + 20 + 21) / 3 = 13.67 ms

Optimal Scheduling:
Time: 0  1  2      22
     |--|--|--------|
     |P2|P3|   P1   |

P1's waiting time = 2 ms
P2's waiting time = 0 ms
P3's waiting time = 1 ms
Average Waiting Time = (2 + 0 + 1) / 3 = 1 ms
```

**Why It's a Significant Disadvantage:**

1. **Poor Average Waiting Time** - Long processes can make many short processes wait
2. **Unfair** - Short jobs are penalized if they arrive after long jobs
3. **Low Responsiveness** - Interactive users must wait if long batch job is running
4. **Inefficient** - System doesn't prioritize quick completions
5. **Unsuitable for Mixed Workloads** - Cannot handle mix of short and long processes efficiently

This is a major reason why FCFS is not used in interactive systems.

---

### Answer 5: FCFS Scheduling Problem Solution

**Given Data:**

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 8         |
| P2      | 2            | 4         |
| P3      | 4            | 2         |
| P4      | 5            | 3         |

**Gantt Chart:**

```
Time:  0       8      12   14    17
      |-------|------|--|----|
      |   P1  |  P2  |P3|P4 |
      |-------|------|--|----|
```

**Completion Times:**
- P1: 8
- P2: 12
- P3: 14
- P4: 17

**Waiting Times:**
- P1: 0 - 0 = 0 ms
- P2: 8 - 2 = 6 ms
- P3: 12 - 4 = 8 ms
- P4: 14 - 5 = 9 ms

**Turnaround Times:**
- P1: 8 - 0 = 8 ms
- P2: 12 - 2 = 10 ms
- P3: 14 - 4 = 10 ms
- P4: 17 - 5 = 12 ms

**Averages:**
- Average Waiting Time = (0 + 6 + 8 + 9) / 4 = 23/4 = **5.75 ms**
- Average Turnaround Time = (8 + 10 + 10 + 12) / 4 = 40/4 = **10 ms**

**CPU Utilization:** (17 - 0) / 17 = 17/17 = **100%** (No idle time)

---

## Question Paper 5 - Answers

### Answer 1: Operations on Processes

**Process Creation:**

**Events that trigger creation:**
1. System initialization - OS creates system processes
2. User request - User submits jobs or runs programs
3. Batch request - Batch jobs are submitted
4. Parent process request - Running process uses fork() to create child

**Creation Process:**
- System allocates memory for program
- OS creates PCB with initial information
- Sets process state to NEW
- Initializes registers, memory pointers
- Allocates file descriptors
- Moves process to READY state

**Process Termination:**

**Events that trigger termination:**
1. Normal completion - Process executes all instructions
2. Fatal error - Illegal operation or protection violation
3. Parent termination - Parent process exits (usually terminates children)
4. User request - User kills the process

**Termination Process:**
- Process executes exit() system call
- OS deallocates process storage and resources
- PCB is updated with exit status
- Parent is notified if process is waiting
- Process moves to TERMINATED state
- PCB may be retained until parent retrieves exit status

These operations are fundamental to process management.

---

### Answer 2: User Mode vs Kernel Mode

**User Mode:**
- Restricted execution environment
- User programs run in this mode
- Can only execute non-privileged instructions
- Cannot directly access hardware or memory
- Can only access own memory space
- System calls needed to access OS services

**Kernel Mode:**
- Privileged execution environment
- OS kernel runs in this mode
- Can execute all instructions including privileged ones
- Can directly access hardware and memory
- Can access any memory location
- No restrictions on operations

**Why This Distinction is Important for Security:**

1. **Protection** - Prevents user programs from directly accessing critical hardware
2. **Isolation** - User processes cannot interfere with each other or kernel
3. **Resource Control** - OS maintains control over hardware resources
4. **Privilege Separation** - Ensures only authorized code can perform privileged operations
5. **Error Containment** - Prevents buggy programs from crashing entire system
6. **Access Control** - Restricts access to sensitive data and operations
7. **Prevent Unauthorized Access** - Users cannot bypass security mechanisms

**Mode Switch:** Occurs through system calls and interrupts. When user process needs OS service, it traps to kernel mode, kernel performs operation, then returns to user mode.

This separation is fundamental to OS security and stability.

---

### Answer 3: System Calls and User-OS Interface

**System Calls:** Programming interface that allows user-level processes to request services from OS kernel.

**How System Calls Work:**

1. **User Process Makes Request** - Program calls system call function (e.g., open(), read())
2. **Parameters Passed** - Function parameters are prepared and passed to kernel
3. **Trap/Software Interrupt** - System call generates interrupt to switch to kernel mode
4. **Kernel Mode** - OS kernel takes control and performs requested operation
5. **Service Execution** - Kernel performs task using privileged instructions
6. **Return to User Mode** - After completion, control returns to user process
7. **Return Value** - Result or status code is returned to user program

**Examples by Category:**

**File System Calls:**
- `open()` - Opens file, returns file descriptor
- `read()` - Reads data from file
- `write()` - Writes data to file
- `close()` - Closes file

**Process Control Calls:**
- `fork()` - Creates child process
- `exec()` - Replaces program with new one
- `exit()` - Terminates process

**Device I/O Calls:**
- `read()` - Reads from device
- `write()` - Writes to device
- `ioctl()` - Issues control commands

System calls provide secure interface between user programs and OS, ensuring controlled access to resources while maintaining security and stability.

---

### Answer 4: FCFS vs Other Scheduling Criteria

**FCFS Scheduling Performance:**

**Average Waiting Time in FCFS:**
- Usually high because short processes must wait for long ones
- Affects user perception of system responsiveness
- Poor for interactive systems

**CPU Utilization in FCFS:**
- Can be poor with I/O-bound processes because CPU becomes idle
- Better with CPU-bound processes
- No preemption means once process gets CPU, it keeps it

**Comparison with Other Criteria:**

| Criterion | FCFS | Optimal Case |
|-----------|------|--------------|
| **Avg Waiting Time** | High | Low (SJF) |
| **Avg Turnaround Time** | High | Low (SJF) |
| **CPU Utilization** | Fair to Poor | High |
| **Response Time** | High | Low (Round Robin) |
| **Fairness** | Good | Varies |
| **Overhead** | Low | Depends |
| **Implementation** | Simple | Complex |

**Disadvantages of FCFS:**
1. **Waiting Time:** Can be very high, especially with convoy effect
2. **CPU Utilization:** Poor with I/O bound processes
3. **Responsiveness:** Not suitable for interactive systems
4. **Long Turnaround Time:** Wastes system time

**Why FCFS is Rarely Used:**
Despite being simple, FCFS generally performs poorly compared to algorithms like:
- Shortest Job First (SJF) - Lower average waiting time
- Round Robin - Better responsiveness and fairness
- Priority Scheduling - Handles different importance levels

Modern systems use more sophisticated algorithms that balance these criteria better.

---

### Answer 5: FCFS Scheduling Problem Solution

**Given Data:**

| Process | Arrival Time | Burst Time |
|---------|--------------|-----------|
| P1      | 0            | 5         |
| P2      | 3            | 2         |
| P3      | 6            | 3         |
| P4      | 8            | 1         |
| P5      | 10           | 4         |

**Gantt Chart:**

```
Time:  0     5   7    10   11    15
      |-----|---|---|----|-----|
      | P1  |P2 |P3 | P4 |  P5 |
      |-----|---|---|----|-----|
```

**Completion Times:**
- P1: 5
- P2: 7
- P3: 10
- P4: 11
- P5: 15

**Waiting Times:**
- P1: 0 - 0 = 0 ms
- P2: 5 - 3 = 2 ms
- P3: 7 - 6 = 1 ms
- P4: 10 - 8 = 2 ms
- P5: 11 - 10 = 1 ms

**Turnaround Times:**
- P1: 5 - 0 = 5 ms
- P2: 7 - 3 = 4 ms
- P3: 10 - 6 = 4 ms
- P4: 11 - 8 = 3 ms
- P5: 15 - 10 = 5 ms

**Averages:**
- Average Waiting Time = (0 + 2 + 1 + 2 + 1) / 5 = 6/5 = **1.2 ms**
- Average Turnaround Time = (5 + 4 + 4 + 3 + 5) / 5 = 21/5 = **4.2 ms**

**CPU Utilization:** (15 - 0) / 15 = 15/15 = **100%** (No idle time)

**Note:** This example shows good average waiting time because all processes arrive close together, minimizing idle time and convoy effect.

---

**Last Updated:** March 2026  
**Author Notes:** This document covers Unit 1 and Unit 2 (up to FCFS) of Operating Systems course for B.Tech Data Science Semester IV.
