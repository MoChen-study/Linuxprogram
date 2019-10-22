#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
char buf[]={"write to stdout\n"};

int main()
{
	pid_t pid;
	write(STDOUT_FILENO,buf,sizeof(buf)-1);

	printf("printf\n");
	pid=fork();
	if(pid<0)
		perror("fork error!");
	return 0;
}
