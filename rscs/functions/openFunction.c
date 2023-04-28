#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char *pathfile = "file.txt";

    // int open(const char *path, int oflag, ... );
    fd = open(pathfile, O_RDONLY);
    if (fd == -1)
    {
        printf("Erro ao acessar o arquivo.");
        return (1);
    }
    printf("O arquivo foi acessado com sucesso.");
    close(fd);
    return (0);

}
