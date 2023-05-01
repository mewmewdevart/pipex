#include <strings.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <sys/wait.h>

int main(int argc, char **argv)
{
	int id = fork();

	/*
		getpid() returns the process ID of the calling process. (This is often used by routines that generate unique temporary filenames.)
		getppid() returns the process ID of the parent of the calling process.
	*/
	if (id == 0) // Always child process terminate before the parent process but in that case, the parent will print first
		sleep(1);
	printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());

	// if (id != 0) Fix the delay with delay in the main process to child process will be executed first
	//	wait(NULL);

	int res = wait(NULL);
	if (res == -1)
		printf("No babies to wait for\n");
	else
		printf("%d finished execution\n", res); // print the information in the parent process
	return (0);
}