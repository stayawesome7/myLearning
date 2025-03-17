int main(void){
	int pid;
	int childStatus;
	int x = 1;
	printf("[+]Parent pid : %d\n",getpid());
	pid = fork();
	
	if(pid==0){
		printf("[-]Child pid : %d\n",getpid());
		x=x+1;
		printf("[-]Child incrementing x : %d\n",x);
		sleep(3);
		exit(33);
	}
	x = x - 1;
	printf("[+]Parent decrementing x : %d\n",x);
	printf("[+]Parent Waiting !!!\n");
	wait(&childStatus);
	printf("[+]Parent Exiting ... with child status %x\n",childStatus);
	return 0;
}
