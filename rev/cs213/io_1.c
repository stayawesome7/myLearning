int main(void){
	char c;
	while(read(0,&c,1024)!=0){
		write(1,&c,1024);
	}
	return 0;
}
