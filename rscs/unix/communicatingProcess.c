#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int fd[2];
    int id;
    // fd[0] - read
    // fd[1] - write

    if (pipe(fd) == -1)
    {
        printf("An error ocurred with opening the pipe!\n");
        return (1);
    }
    id = fork();
    if (id == - 1)
    {
        printf("An error ocurred with  fork()!\n");
        return (2);
    }
    if (id == 0) // child process take the input
    {
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        if (write(fd[1], &x, sizeof(int)) == -1)
        {
            printf("An error ocurred with writing to the pipe!\n");
            return (3);
        }
        close(fd[1]);
    } else { // parent process print the input in output
        int y;
        if (read(fd[0], &y, sizeof(int)) == -1)
        {
            printf("An error ocurred with reading to the pipe!\n");
            return (4);
        }
        // y = y * 3
        close(fd[0]);
        printf("Got from child process %d", y);
    }
    return (0);
}