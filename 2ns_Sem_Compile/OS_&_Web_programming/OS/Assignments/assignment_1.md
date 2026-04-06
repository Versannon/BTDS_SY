Assignment 1:

1: What is Kernal and explain all functionalities of Kernal?

-> The kernel is the core component of an operating system that manages system resources and allows software to interact with hardware. Its functionalities include:
- Process management: Creating, scheduling, and terminating processes.
- Memory management: Allocating and deallocating memory for processes.
- File system management: Handling file operations and storage.
- Device management: Managing input/output devices and drivers.
- Security and protection: Controlling access to resources and ensuring system integrity.
- Networking: Facilitating communication between processes and systems.

2: What is system cll and explain all types of system call?

-> A system call is a mechanism that allows user programs to request services from the operating system's kernel. Types of system calls include:
- Process control: `fork()`, `exec()`, `wait()`
- File management: `open()`, `read()`, `write()`, `close()`
- Device management: `ioctl()`, `read()`, `write()`
- Information maintenance: `getpid()`, `alarm()`
- Communication: `pipe()`, `socket()`
- Protection: `chmod()`, `chown()`

3: What is fork(), explain it with example.

-> The `fork()` system call is used to create a new process by duplicating the calling process. The new process is called the child process, and the original process is called the parent process. Both processes will execute the same code after the `fork()` call, but they will have different process IDs.

Example:
```c
#include <stdio.h>
#include <unistd.h>
int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This is the child process
        printf("Hello from the child process! PID: %d\n", getpid());
    } else if (pid > 0) {
        // This is the parent process
        printf("Hello from the parent process! PID: %d\n", getpid());
    } else {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    }

    return 0;
}
```In this example, the `fork()` call creates a child process. Both the parent and child processes will print their respective messages along with their process IDs.

4: Difference between Program and Process?

-> A program is a static set of instructions stored on disk, while a process is a dynamic instance of a program in execution. A program becomes a process when it is loaded into memory and starts executing. A process has its own memory space, system resources, and execution context, whereas a program is just a file that contains code.

5: Explain PCB(Process Control Block) with a diagram.

-> The Process Control Block (PCB) is a data structure used by the operating system to store information about a process. It contains details such as the process ID, process state, CPU registers, memory management information, and open file descriptors.


6: Explain Process state trasition diagram.

-> 