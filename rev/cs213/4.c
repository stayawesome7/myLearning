#include <stdio.h>
#include <unistd.h>

int main() {
    printf("This is buffered ");  // Stays in buffer
    sleep(5);                     // Wait, buffer not flushed yet
    printf("output!");
    sleep(5);                     // Still in buffer
//    printf("\n");                  // Now, buffer flushes automatically
    return 0;
}

