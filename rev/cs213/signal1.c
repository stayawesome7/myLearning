#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig) {
    printf("\nCaught signal %d: Ctrl+C is disabled!\n", sig);
}

int main() {
    signal(SIGINT, SIG_IGN); // Handle SIGINT (Ctrl + C)
    
    while (1) {
        printf("Running... Press Ctrl+C to try to stop me!\n");
        sleep(2);
    }

    return 0;
}

