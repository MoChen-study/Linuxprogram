#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int global=4;
int main()
{
	pid_t pid;
	int vari=5;
	printf("before fork\n");
	if((pid=fork())<0){
	printf("fork error\n");
	_exit(0);
	}else if(pid==0){
		global++;
		vari--;
		printf("Child changed!\n");
	}else
	printf("Parent did not changed\n");
	printf("global=%d vari=%d\n",global,vari);
	_exit(0);

}
