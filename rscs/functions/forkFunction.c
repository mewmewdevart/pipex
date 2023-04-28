#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//reference: https://www.section.io/engineering-education/fork-in-c-programming-language/#:~:text=In%20the%20computing%20field%2C%20fork,also%20kills%20the%20child%20process.
int main (void)
{
	// Fork a process
	fork();
	// The child and parent will execute every line of code after the fork (each separately)
	printf("Hello World!\n");

	return (0);
}
