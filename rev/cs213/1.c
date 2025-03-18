#include<stdio.h>
void parse_input(char *input, char **args) {
    char *token = strtok(input, " \n"); // Tokenize input using space and newline
    printf("%s\n",token);
    /*
    int i = 0;
    while (token != NULL) {
        args[i++] = token;  // Store each argument
        token = strtok(NULL, " \n");
    }
    args[i] = NULL;  // Null-terminate the argument list
		     */
}

int main(void){
	char *args[10];
	int i=0;
	while(i<10){
		printf("%d : %d\n",i,i++);
	}
	char input[1024];
	fgets(input,sizeof(input),stdin);
	printf("Input entered is : %s",input);
	parse_input(input,args);
	return 0;
}

