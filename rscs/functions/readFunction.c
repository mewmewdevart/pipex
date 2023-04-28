#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main (void)
{
    int fd;
    char *pathfile = "file.txt";
    char buffer[BUFFER_SIZE];
    size_t numb_bytes;
    size_t bytes_read;
    

    // ssize_t read(int fildes, void *buf, size_t nbyte);
    fd = open(pathfile, O_RDONLY);
    if (fd == -1)
    {
        printf("Erro ao acessar o arquivo.");
        return (1);
    }

    numb_bytes = sizeof(buffer);
    bytes_read = read(fd, buffer, numb_bytes);

    printf("Bytes lidos = %ld\n", bytes_read);
    printf("Buffer read = %s\n", buffer);

    close(fd);
    return (0);
}
