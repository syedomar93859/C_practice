/*
Run this program several time to demonstrate that the parent can quit while
the child is still running
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
	pid = fork();
	
	if (pid < 0) {
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) {
		int i;
		for (i = 0; i < 30; i++) {
			printf("I am the child\n");
		}
		printf("the child is done\n");
		exit(0);
	}
	else {
		printf("I am the parent\n");	
		//wait(NULL);
		//printf("Child Complete");
	}
	printf("The parent is done\n");
	exit(0);
}

