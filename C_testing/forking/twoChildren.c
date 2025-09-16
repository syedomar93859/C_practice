/*
Forking more than one child
*/
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int fromChild;

	pid = fork();
	
	if (pid < 0) {
		printf("Fork Failed");
		exit(-1);
	}
	else if (pid == 0) {
		printf("Child 1: I am going to sleep\n");
		sleep(5);
		printf("Child 1: I am up\n");
		exit(1);
	}
	else {
		printf("Parent: I will create a new child\n");	
		pid = fork();
		if (pid < 0) {
			printf("Fork Failed");
		}	
		else if (pid == 0) {
		printf("Child 2: I am alive\n");
		exit(2);
		} else {
			wait(&fromChild);
			printf("Child %d is done\n", WEXITSTATUS(fromChild));
			wait(&fromChild);
			printf("Child %d is done\n", WEXITSTATUS(fromChild));
			printf("Children Completed\n" );
		}
	}
	printf("The parent is done\n");
	exit(0);
}

