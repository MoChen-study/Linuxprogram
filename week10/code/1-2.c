#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int g=88;
int main()
{

	int v=99;
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(0);
	}
	else if(pid==0)
	{

		g++;
		v++;
		printf("child:pid=%d,g=%d,v=%d\n",getpid(),g,v);
		//return 0;
		//exit(0);
		_exit(0);
	}
	else
	{
		printf("return value=%d\n",pid);
		printf("parent:pid=%d,g=%d,v=%d\n",getpid(),g,v);
		//return 0;
		//exit(0);
		_exit(0);
	}
}
