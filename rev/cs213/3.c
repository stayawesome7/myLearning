#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler2(int sig) {
    printf("[Handler 2] Executing!\n");
}

void handler1(int sig) {
    printf("[Handler 1] Received signal. Triggering SIGUSR2...\n");

    raise(SIGUSR2);  // Interrupts handler1() and jumps to handler2()
    
    printf("[Handler 1] Resuming execution.\n");
}

int main() {
    signal(SIGUSR1, handler1);
    signal(SIGUSR2, handler2);

    printf("PID: %d\n", getpid());

    while (1) pause();  // Wait for signals
}

