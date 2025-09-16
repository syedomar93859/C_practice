/*
Demontsrates how a child communicates with parent through exit and wit
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
	int toParent;
	int fromChild;

	pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) {
		printf("I am the child\n");
		sleep(1); // allow parent to wait
		printf("Enter an integer between 0 and 255: ");
		scanf("%d", &toParent);
		exit(toParent);
	}
	else {
		printf("I am the parent\n");	
		wait(&fromChild);
		printf("Child Completed with %d \n", WEXITSTATUS(fromChild));
	}
	printf("The parent is done\n");
	exit(0);
}

