#include <stdio.h>      // For printf
#include <pthread.h>    // For pthread functions
#include <stdlib.h>     // For malloc, free (if needed)
#include <unistd.h>     // For sleep

char **ptr;

void * thread(void * vargp){
	int id =  (int) vargp;
	printf("thread run\n");
	printf("%d : %s",id,ptr[id]);
	return NULL;
}

int main(void){
	pthread_t tid[2];
	int i;
	char * msg[2]={"Hello AJAY","BYE AJAY"};
	ptr = msg;
	for (i=0; i<2;i++){
//		printf("%s\n",msg[i]);		
		pthread_create(&tid[i],NULL,thread,(void *)i);
	}
	 for (int i = 0; i < 2; i++) {
        	pthread_join(tid[i], NULL);
   	 }

	

	return 0;
}
