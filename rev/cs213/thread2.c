#include <stdio.h>      
#include <pthread.h>    
#include <stdlib.h>     
#include <unistd.h>     

char **ptr; // Global pointer to array of strings

void *thread(void *arg) {  
    int id = *(int *)arg; // Convert void* to int
    free(arg); // Free allocated memory

    printf("Thread %d running\n", id);
    printf("%d : %s\n", id, ptr[id]);

    return NULL;
}

int main(void) {
    pthread_t tid[2]; // Store thread IDs
    char *msg[2] = {"Hello AJAY", "BYE AJAY"};  
    ptr = msg; // Assign global pointer

    for (int i = 0; i < 2; i++) {
        int *arg = malloc(sizeof(int)); // Allocate memory for thread argument
        *arg = i; // Store loop variable
        pthread_create(&tid[i], NULL, thread, arg);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 2; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}

