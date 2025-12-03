#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>
#include <signal.h>
#include <errno.h>

int main(void)
{
	pid_t pid;
	int status;

	if ((pid = fork()) < 0)
	{
		status = -1;
	}
	else if (pid == 0)
	{
		execl("/bin/sh", "sh", "-c", "./child", (char *)0);
	}

	while (1)
	{
		sleep(1);
		printf("Parent");
	}

	printf("end of program");
}

