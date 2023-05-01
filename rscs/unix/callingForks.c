#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <errno.h>

int main(int argc, char **argv)
{
    int id1 = fork();
    int id2 = fork();

    for (int i = 0; i < 10; i++) // just for a test
        fork();

    if(id1 == 0) // child process
    {
        if (id2 == 0) // child process of child process
            printf("We are process y!\n");
        else
            printf("We are process x!\n");
    } else {
        if (id2 == 0)
        {
            printf("We are process z!\n");
        } else {
            printf("We are the parent process!\n");
        }
    }
    //wait(NULL); // wait only one process to finish
    while (wait(NULL) != -1 || errno != ECHILD)
    {
        printf("Waited fort a child to finish!\n");
        }
    return (0);
}