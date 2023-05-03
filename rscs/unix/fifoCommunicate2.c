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
    int i;
    char *pathfile = "sum";

    // Abre o FIFO de SUM para leitura
    int fd = open(pathfile, O_RDONLY);
    if (fd == -1)
        return 1;

    // Lê os valores do FIFO
    for (i = 0; i < 5; i++)
    {
        if (read(fd, &arr[i], sizeof(int)) == -1)
            return 1;
        printf("Received: %d\n", arr[i]);
    }

    // Fecha o FIFO
    close(fd);

    int sum = 0;
    for (i = 0; i < 5; i++)
	    sum += arr[i];
    printf("Result is %d\n", sum);
    return (0);
}

