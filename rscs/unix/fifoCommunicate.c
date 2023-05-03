#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#include <math.h>
#include <time.h>

int main(int argc, char **argv)
{
    int arr[5];
    char *pathfile = "sum";
    int i;

    // Cria o FIFO
    mkfifo(pathfile, 0666);

    // Abre o FIFO para escrita
    int fd = open(pathfile, O_WRONLY);
    if (fd == -1)
        return 1;

    // Preenche o array com valores aleatórios
    srand(time(NULL));
    for (i = 0; i < 5; i++)
        arr[i] = rand() % 100;

    // Escreve os valores no FIFO
    for (i = 0; i < 5; i++)
    {
        if (write(fd, &arr[i], sizeof(int)) == -1)
            return 1;
        printf("Wrote: %d\n", arr[i]);
    }

    // Fecha o FIFO
    close(fd);
    return 0;
}

