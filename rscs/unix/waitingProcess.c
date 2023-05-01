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
	/*
	Before wait() the output is:
	6 7 8 9 10 
	1 2 3 4 5 

	After wait() the output is:
	1 2 3 4 5 
	6 7 8 9 10

	*/

	i = n;
	while(i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout); // flush a stream
		i++;
	}
	// add if (id != 0) to print all numbers in a sequence: 1 2 3 4 5 6 7 8 9 10 
	printf("\n");
	return (0);
}
