#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

/*
    Escreva um programa que utilize a função fork() para criar um processo filho que imprime um contador crescente a cada segundo, enquanto o processo pai aguarda um tempo especificado e, em seguida, mata o processo filho.
*/
int main(void)
{
    int id = fork();
    int i;

    if (id == 0)
    {
        for(i = 1; ;i++)
        {
            printf("Filho: %d\n", i);
            sleep(1);
        }
        exit(1);
    } else {
        sleep(5);
        printf("Pai matando o processo filho...\n");
        kill(id, SIGKILL);
        wait(NULL);
        printf("Pai matou o filho!\n");
    }
    return (0);
}