#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World! Welcome to C programming."; 
    char *token = strtok(str, " ,.!"); // Delimiters: space, comma, dot, and exclamation mark

    while (token != NULL) {
        printf("%s\n", token);  // Print each token
        token = strtok(NULL, " ,.!"); // Get next token
    }

    return 0;
}

