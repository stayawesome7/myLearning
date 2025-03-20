#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nSIGINT received! (Ctrl+C)\n");
}

int main() {
    sigset_t block_set, old_set;

    // Register SIGINT handler
    signal(SIGINT, sigint_handler);

    // Initialize the signal set and add SIGINT
    sigemptyset(&block_set);
    sigaddset(&block_set, SIGINT);

    printf("Press Ctrl+C... (SIGINT will be blocked during the critical section)\n");

    // Block SIGINT
    sigprocmask(SIG_BLOCK, &block_set, &old_set);

    // Critical section (SIGINT won't interrupt this)
    printf("Entering critical section...\n");
    sleep(5);  // Simulating important work
    printf("Exiting critical section...\n");

    // Restore previous signal mask (unblock SIGINT)
    sigprocmask(SIG_SETMASK, &old_set, NULL);

    printf("SIGINT is now unblocked. Try pressing Ctrl+C again!\n");

    while (1) pause();  // Wait for signals

    return 0;
}

