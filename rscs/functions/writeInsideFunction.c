#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (void)
{
    int fd;
    size_t returnWrite;
    const char *msg = "Hello World!";
    char *pathfile = "output.txt";

    fd = open(pathfile, O_WRONLY | O_CREAT); //Se o arquivo naoexistir, ele é criado
    if (fd == -1)
    {
        printf("Erro ao abrir o arquivo.");
        return (1);
    }

    returnWrite = write(fd, msg, strlen(msg));
    if (returnWrite == -1)
    {
        printf("Erro ao escrever no arquivo");
        return (1);
    }

    close(fd);

    return (0);
}
