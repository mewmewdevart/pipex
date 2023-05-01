#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

// wait() for process to change state

int main(int argc, char **argv)
{
	int n;
	int i;
	int id;

	id = fork();
	if (id == 0)
		n = 1;  // child process
	else
		n = 6; // main(parent) process

	if (id != 0) // using it to wait child process do the action for after calling the main process
		wait(); // it wait the child process finish the process to continue the execution of parent

	i = n;
	while(i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout); // flush a stream
		i++;
	}
	if (id != 0)
		printf("\n");
		/*
	Always child process terminate before the parent process
	Parent process:
		argc = 1
		argv = "main.exe"
		n = 6
		id = 4300
		i = 11 // the loop-count inside while
	Child process:
		argc = 1
		argv = "main.exe"
		n = 1
		id = 0
		i = 6
	*/

	return (0);
}
