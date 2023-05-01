#include <stdio.h>
#include <unistd.h>

/*
	File Descriptor Table:
		fd[0] = input(stdin)
		fd[1] = output(stdout)
		fd[2] = error(stderr)

*/

int main()
{
	int fd[2];
	pid_t pid; // A variavel pid ira receber um dado PID (Process ID) de um processo pid_t

	//  Create a pipe
	/*
		A função pipe() é responsável por criar um canal de comunicação entre dois processos, 
			permitindo que eles compartilhem dados por meio de um fluxo unidirecional de bytes.
	*/
	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (1);
	}

	// Create a new process
	if((pid = fork()) == -1)
	{
		perror("fork");
		return(1);
	}

	// Child process : read
	if (pid == 0)
	{
		char buffer[1024];
		int read_bytes;

		// Close the fd[1]
		close(fd[1]);

		// Read the data of pipe
		read_bytes = read(fd[0], buffer, sizeof(buffer));
		// Print the read data
		printf("Child: Lê %d bytes: %.*s\n", read_bytes, read_bytes, buffer);
		
		// CLose the read of pipe
		close(fd[0]);

	} else { // Parent process : write
		// Close the read of pipe
		close(fd[0]);

		// Write data in pipe
		write(fd[1], "Hello, world!", 13);

		// Close the write of pipe
		close(fd[0]);
	}


	return (0);
}