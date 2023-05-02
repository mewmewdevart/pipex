#include <stdio.h>
#include <unistd.h>

/*
    1. Escreva um programa simples que utiliza a função fork() para criar um processo filho e exibir "Hello, world!" em ambos os processos.
*/

int main(void)
{
    int id = fork();

    if (id == 0)
        printf("Hello, world!\n");
    else
        printf("Hello, world!\n");

    return (0);
}