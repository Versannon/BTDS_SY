# Operating Systems - Unit I Notes

Course: `BTDS-212-PCC: Operating Systems`  
Source: `Portion.pdf` (Unit-I syllabus)

## Unit-I: Operating System - Introduction

### 1. Operating System (OS): Meaning and Purpose
1. An Operating System (OS) is system software that acts as an interface between user programs and hardware.
2. It manages computer resources:
3. CPU
4. Main memory
5. I/O devices
6. Secondary storage and files
7. Primary goals of OS:
8. Convenience: easier system usage for user/programmer.
9. Efficiency: better hardware utilization.
10. Evolution: easy support for new hardware and features.
11. Examples of OS:
12. Desktop: Windows, Linux, macOS
13. Mobile: Android, iOS
14. Real-time/embedded: FreeRTOS, VxWorks

### 2. OS Structures / Types (as per syllabus)
1. **Simple Batch System**
2. Jobs are collected in batches and executed sequentially.
3. No direct interaction during execution.
4. High turnaround time, less user convenience.
5. Example: salary processing jobs executed overnight.
6. **Multiprogrammed System**
7. Multiple programs are kept in memory together.
8. CPU switches to another job when current job waits for I/O.
9. Improves CPU utilization.
10. Example: while a compiler waits for disk input, text editor gets CPU.
11. **Time-Shared System**
12. CPU time is divided into small time slices among users/processes.
13. Supports interactive multi-user environment.
14. Fast response time is expected.
15. Example: many students running commands on one lab server.
16. **Personal Computer System**
17. Primarily single-user system.
18. Focus on responsiveness and user-friendly GUI.
19. Example: laptop running browser, IDE, music player.
20. **Parallel System**
21. Uses multiple processors/cores in one system.
22. Improves throughput and reliability.
23. Also called tightly coupled multiprocessor system.
24. Example: multi-core rendering or scientific simulation.
25. **Distributed System**
26. Multiple networked computers cooperate to solve tasks.
27. Resource sharing and scalability are key benefits.
28. Example: distributed storage and cloud computing clusters.
29. **Real-Time System**
30. Correctness depends on output plus timing deadline.
31. Used in control and safety-critical applications.
32. Example: airbag control, ICU monitoring, robotic control.
33. Types:
34. Hard real-time: deadline miss is unacceptable.
35. Soft real-time: occasional deadline miss is acceptable.

### 3. System Components
1. **Process Management**
2. Creates, schedules, suspends, resumes, and terminates processes.
3. Example: browser and media player run as independent processes.
4. **Memory Management**
5. Tracks free/used memory and allocates/deallocates memory to processes.
6. Handles logical to physical address mapping.
7. Example: one process cannot directly access another process memory.
8. **File System Management**
9. Manages files/directories, names, permissions, and storage organization.
10. Example: creating `notes.txt` with read/write permissions.
11. **I/O System Management**
12. Manages device drivers, buffering, caching, and spooling.
13. Example: print spooler queues multiple print requests.
14. **Secondary Storage Management**
15. Handles disk scheduling, free-space tracking, and block allocation.
16. Example: selecting disk request order to reduce seek time.
17. **Protection and Security**
18. Controls access via authentication and authorization.
19. Example: user login + file permissions.
20. **Networking / Communication**
21. Supports communication across processes and systems.
22. Example: browser uses OS networking stack for internet access.
23. **Command Interpreter / UI**
24. Provides shell/GUI interface to user.
25. Example: Bash, PowerShell, Command Prompt, desktop UI.

### 4. Operating System Services
1. Program execution: load, run, and terminate programs.
2. I/O operations: controlled read/write to devices.
3. File-system manipulation: create/open/read/write/rename/delete files.
4. Communication: data exchange between processes/systems.
5. Error detection: detects CPU, memory, I/O, and program errors.
6. Resource allocation: allocates CPU, memory, devices, and files.
7. Accounting: tracks resource usage and performance.
8. Protection and security: isolates users/processes and protects data.
9. Example mapping:
10. Opening a file in an editor uses file-system service + I/O service.
11. Running multiple apps uses execution + CPU allocation services.

### 5. System Calls
1. System calls are the programming interface to OS kernel services.
2. User programs call system calls when privileged operations are required.
3. Major categories:
4. Process control
5. File management
6. Device management
7. Information maintenance
8. Communication
9. Protection
10. Typical Unix/Linux examples:
11. `fork()` -> create child process
12. `exec()` -> replace process image with new program
13. `wait()` / `waitpid()` -> wait for child process
14. `open()`, `read()`, `write()`, `close()` -> file operations
15. Why required:
16. User mode has restricted privileges.
17. Kernel mode has full hardware access.
18. System call creates controlled transition from user mode to kernel mode.

### 6. Process: Concept and Scheduling
1. A process is a program in execution.
2. Process contents:
3. Code/text section
4. Data section
5. Stack
6. Current CPU context (program counter + registers)
7. Process metadata stored in PCB (Process Control Block):
8. PID, state, scheduling info, memory pointers, open files.
9. Basic process states:
10. New
11. Ready
12. Running
13. Waiting/Blocked
14. Terminated
15. Scheduling:
16. OS scheduler selects a ready process for CPU.
17. Goals: high CPU utilization, better throughput, low response time.
18. Example state transition:
19. Program start: `New -> Ready -> Running`
20. Wait for disk I/O: `Running -> Waiting`
21. I/O completion: `Waiting -> Ready`
22. CPU assigned: `Ready -> Running`

### 7. Operations on Processes
1. Process creation
2. Process termination
3. Process suspension and resumption
4. Context switching (save old process state and restore new state)
5. Parent-child relationships
6. Practical examples:
7. Shell starts a command -> child process creation.
8. Command completion -> exit status returned to parent shell.
9. Context-switch cost is overhead (management time, no user progress).

### 8. Cooperating Processes
1. Cooperating processes can affect or be affected by other processes.
2. Why cooperation is needed:
3. Information sharing
4. Computation speedup
5. Modularity
6. Convenience
7. Main issue: race condition when shared data is accessed concurrently.
8. Example: Producer-Consumer
9. Producer inserts item in shared buffer.
10. Consumer removes item from same buffer.
11. Without synchronization, buffer counters may become inconsistent.
12. Controlled synchronization avoids this problem.

### 9. Threads
1. Thread is the smallest unit of CPU execution.
2. A process may contain multiple threads.
3. Threads in same process share code/data/address space.
4. Benefits:
5. Better responsiveness
6. Better resource sharing
7. Lower overhead than processes
8. Better parallelism on multicore systems
9. Example:
10. Browser thread 1 handles UI.
11. Browser thread 2 downloads data.
12. Browser thread 3 renders content.
13. Quick Process vs Thread:
14. Process: separate memory, heavier creation, costlier communication.
15. Thread: shared memory, lighter creation, faster communication.

## Quick Revision (Exam-Focused)
1. Define Operating System and list its goals.
2. Differentiate Batch, Multiprogramming, and Time-Sharing systems.
3. Explain Distributed vs Parallel systems with examples.
4. List OS components and their functions.
5. Explain OS services and system calls.
6. Define process and explain process states with transition.
7. Explain cooperating processes and race condition.
8. Define thread and advantages of multithreading.

## Short Viva Q&A
1. What does an OS do first when a program starts?
2. It loads program into memory, allocates resources, and schedules CPU.
3. Why is multiprogramming useful?
4. It keeps CPU busy by switching to another ready job during I/O wait.
5. Why are system calls required?
6. They provide safe access to kernel services from user programs.
7. Why are threads preferred in interactive apps?
8. They improve responsiveness by overlapping UI and background work.
