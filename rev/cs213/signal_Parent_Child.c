#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler(int sig) {
    printf("Parent process received signal %d\n", sig);
}

int main() {
    pid_t pid;
    signal(SIGUSR1, signal_handler);  // Setup signal handler

    pid = fork(); // Create a child process

    if (pid == 0) {
        // Child Process: Send SIGUSR1 to parent but sleep first
        sleep(2); 
        kill(getppid(), SIGUSR1); // Send signal to parent
        printf("Child sent SIGUSR1 to parent\n");
    } else {
        // Parent Process: Simulate context switch
        printf("Parent is working...\n");
        sleep(4); // Simulate doing work before checking for signals
        printf("Parent finished work.\n");
        wait(NULL); // Wait for child to exit
    }
    
    return 0;
}
/*
 
Parent process starts running.
Child process is created (fork()).
Child sleeps (simulating a delay before sending a signal).
Parent continues execution (sleep(4)) → This simulates a context switch where the OS switches to another process.
Child sends SIGUSR1 to the parent.
Parent resumes execution after sleeping.
*/
