#include <stdio.h>

int main() {
    char str[] = "Pointer";
   // char *ptr = str;  // Pointer to the string

    while (*str != '\0') {
        printf("%c ", *str);
        str = str+1; // Move the pointer to the next character
    }
    return 0;
}

