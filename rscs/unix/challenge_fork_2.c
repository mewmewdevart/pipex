#include <stdio.h>
#include <unistd.h>

/*
    2. Crie um programa que utilize a função fork() para criar um processo filho. O processo pai deve exibir o PID do processo filho, enquanto o processo filho deve exibir o PID do próprio processo.
*/

int main(void)
{
    int id = fork();

    if (id == 0)
        printf("PID do processo filho: %d\n", getpid()); // Get the process ID
    else
        printf("PID do processo filho criado: %d\n", id); // getppid for parent process

    return(0);
}