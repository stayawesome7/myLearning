#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void signal_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("Received SIGUSR1: Custom user signal 1!\n");
    } else if (sig == SIGUSR2) {
        printf("Received SIGUSR2: Custom user signal 2!\n");
    } else {
        printf("Received signal %d\n", sig);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2 && argv[1][0] == 'r') { // Receiver Process
        printf("Receiver process PID: %d\n", getpid());

        // Register signal handlers
        signal(SIGUSR1, signal_handler);
        signal(SIGUSR2, signal_handler);

        printf("Waiting for signals... Send SIGUSR1 or SIGUSR2 using `kill`.\n");

        while (1) {
            pause(); // Wait for signals
        }
    } else if (argc == 3 && argv[1][0] == 's') { // Sender Process
        pid_t receiver_pid = atoi(argv[2]);
        if (kill(receiver_pid, 0) == -1) {
            perror("Error: Invalid PID or process not running");
            return 1;
        }

        printf("Sending signals to process PID %d...\n", receiver_pid);

        sleep(1);
        kill(receiver_pid, SIGUSR1); // Send SIGUSR1
        printf("Sent SIGUSR1\n");

        sleep(1);
        kill(receiver_pid, SIGUSR2); // Send SIGUSR2
        printf("Sent SIGUSR2\n");

        return 0;
    } else {
        printf("Usage:\n");
        printf("  Receiver process: %s r\n", argv[0]);
        printf("  Sender process: %s s <receiver_pid>\n", argv[0]);
        return 1;
    }
}

