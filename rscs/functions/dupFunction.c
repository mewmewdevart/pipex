#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int newfd;
	int newnewfd;

	fd = open("larissa.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erro ao acessar o arquivo.");
		return (1);
	}
	printf("Antes de dup: %d\n", fd);

	newfd = dup(fd);
	printf("Novo newfd: %d\n", newfd); // dup() uses the lowest-numbered unused descriptor for the new descriptor.

	newnewfd = dup2(fd, newfd);
	printf("Novo newnewfd: %d\n", newnewfd); // dup2() makes newfd be the copy of oldfd, closing newfd first if necessary

	close(fd);
	return (0);
}
