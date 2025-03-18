#include <stdio.h>

void printString(char *str) {
/*    while (*str != '\0') {
        printf("%c", *str);
        str++;
    }*/

	
    printf("%s\n",str);
}

int main() {
    char str[] = "Pointer Function";
    printString(str);
    return 0;
}

