#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Define the number of processes
#define NUM_PROCESSES 5

// Simulated process structure
typedef struct {
    int id;
    int requesting;
    int granted;
} Process;

// Simulated centralized server
int server;

// Initialize processes
void initProcesses(Process processes[]) {
    for (int i = 0; i < NUM_PROCESSES; i++) {
        processes[i].id = i;
        processes[i].requesting = 0;
        processes[i].granted = 0;
    }
}

// Simulate process requesting the critical section
void requestCriticalSection(Process* process) {
    process->requesting = 1;
    printf("Process %d is requesting access to the critical section...\n", process->id);
}

// Simulate server granting access to the critical section
void grantAccess(Process* process) {
    process->requesting = 0;
    process->granted = 1;
    printf("Server grants access to Process %d for the critical section.\n", process->id);
}

// Simulate process releasing the critical section
void releaseCriticalSection(Process* process) {
    process->granted = 0;
    printf("Process %d releases the critical section.\n", process->id);
}

int main() {
    Process processes[NUM_PROCESSES];
    initProcesses(processes);

    while (1) {
        // Simulate each process requesting access
        for (int i = 0; i < NUM_PROCESSES; i++) {
            requestCriticalSection(&processes[i]);
            sleep(1);  // Simulate some work
            grantAccess(&processes[i]);
            releaseCriticalSection(&processes[i]);
        }
    }
    return 0;
}
