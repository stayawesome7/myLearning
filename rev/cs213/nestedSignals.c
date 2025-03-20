#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr2_handler(int sig) {
    printf("[SIGUSR2 Handler] Executing now!\n");
}

void sigusr1_handler(int sig) {
    printf("[SIGUSR1 Handler] Received. Triggering SIGUSR2...\n");

    // Manually raise SIGUSR2 while SIGUSR1 is executing
    raise(SIGUSR2);

    printf("[SIGUSR1 Handler] Resuming after SIGUSR2.\n");
}

int main() {
    // Register signal handlers
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("Process ID: %d\n", getpid());
    printf("Send signals using: \n  kill -USR1 %d\n  kill -USR2 %d\n", getpid(), getpid());

    // Wait for signals indefinitely
    while (1) {
        pause();
    }

    return 0;
}
/*
 ✔ Nested signals occur when one handler triggers another signal before completing.
✔ By default, signals can interrupt each other unless blocked.
✔ Use sigaction() with sa_mask to prevent signal nesting.
 */
