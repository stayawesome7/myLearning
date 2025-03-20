#include <stdio.h>
#include <string.h>

// Function to print all command-line arguments
void print_arguments(int argc, char *argv[]) {
    printf("Arguments passed to the program:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
}

// Function to count the length of the first argument
void count_length(char *arg) {
    if (arg != NULL) {
        printf("Length of the first argument (%s): %ld\n", arg, strlen(arg));
    } else {
        printf("No argument provided.\n");
    }
}

// Function to manipulate an argument (convert to uppercase)
void manipulate_argument(char *arg) {
    if (arg != NULL) {
        printf("Original argument: %s\n", arg);
        for (int i = 0; arg[i] != '\0'; i++) {
            arg[i] = toupper(arg[i]); // Convert each character to uppercase
        }
        printf("Modified argument: %s\n", arg);
    } else {
        printf("No argument to manipulate.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <argument1> [argument2] ...\n", argv[0]);
        return 1; // Exit if no arguments are provided
    }

    // Call function to print arguments
    print_arguments(argc, argv);

    // Call function to count length of first argument
    count_length(argv[1]);

    // Call function to manipulate the first argument
    manipulate_argument(argv[1]);

    return 0;
}

