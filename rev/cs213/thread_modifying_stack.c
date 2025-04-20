#include <stdio.h>
#include <pthread.h>

void *thread_func(void *arg) {
    int *ptr = (int *)arg;  // Accessing the passed stack variable
    printf("Thread accessing main's stack variable: %d\n", *ptr);
    *ptr = 200;  // Modifying the main thread's stack variable
    return NULL;
}

int main() {
    pthread_t thread;
    int stack_var = 100;  // Stack variable in the main thread

    pthread_create(&thread, NULL, thread_func, &stack_var);
    pthread_join(thread, NULL);

    printf("Main thread sees modified value: %d\n", stack_var);
    return 0;
}

