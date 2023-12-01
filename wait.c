#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	//pid_t ppid;
	//pid = getppid();
	pid = fork();
	if (pid == -1)
	{
		perror("unsuccessful");
		return 1;
	}
	if (pid == 0)
	{
		//sleep(10);
		printf("i am the child\n");
	}
	else
	{
		//ppid = getppid();
		wait(NULL);
		sleep(30);
		printf("i am the parent\n");
		//printf("Parent pid : %u\n", pid);
	}
	return 0;
}
