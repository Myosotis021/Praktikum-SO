#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(void)
{
	pid_t pid;

	pid = fork();

	if (pid > 0) {
		printf("Parent (pid=%d) sleeping (not calling wait)\n", getpid());
		sleep(30);
		printf("Parent done\n");
	}
	else if (pid == 0) {
		printf("Child (pid=%d) exiting now\n", getpid());
		exit(42);
	}
	else {
		perror("fork");
		exit(1);
	}

	return 0;
}

