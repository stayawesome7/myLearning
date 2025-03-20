#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("\nReceived SIGINT! (Ctrl+C)\n");
}

int main() {
    struct sigaction sa;
    sigset_t new_mask, old_mask;

    // Set up SIGINT handler
    sa.sa_handler = sigint_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    // Block SIGINT
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGINT);
    sigprocmask(SIG_BLOCK, &new_mask, &old_mask);

    printf("SIGINT is now blocked. Try pressing Ctrl+C...\n");
    sleep(5);

    // Unblock SIGINT
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
    printf("SIGINT is now unblocked. Press Ctrl+C again!\n");

    while (1) pause();  // Wait for signals

    return 0;
}

