#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Global pointer to store Thread 1's stack variable address
int *thread1_stack_ptr = NULL;

void *thread_func1(void *arg) {
    int stack_var = 42;  // Local stack variable for Thread 1
    thread1_stack_ptr = &stack_var;  // Expose stack variable to other thread

    printf("[Thread 1] Stack variable initially: %d (Address: %p)\n", stack_var, (void*)&stack_var);
    
    // Sleep to allow Thread 2 to modify it
    sleep(2);

    // Check if value is changed
    printf("[Thread 1] Stack variable after Thread 2 modification: %d\n", stack_var);
    
    return NULL;
}

void *thread_func2(void *arg) {
    // Sleep to ensure Thread 1 initializes its variable
    sleep(1);

    if (thread1_stack_ptr) {
        printf("[Thread 2] Modifying Thread 1's stack variable at %p\n", (void*)thread1_stack_ptr);
        *thread1_stack_ptr = 999;  // Directly modifying another thread's stack (DANGEROUS)
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create two threads
    pthread_create(&thread1, NULL, thread_func1, NULL);
    pthread_create(&thread2, NULL, thread_func2, NULL);

    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

