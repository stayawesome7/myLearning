#include <stdio.h>
#include <signal.h>

void handler(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigaction(SIGINT, &sa, NULL);  // Handle SIGINT using sigaction

    while (1) {
        printf("Running...\n");
        sleep(2);
    }

    return 0;
}

