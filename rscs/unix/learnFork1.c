#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Escreva um programa em C que chama a função fork() e cria um processo filho. O processo filho deve imprimir "Processo filho criado!" na tela, enquanto o processo pai deve imprimir "Processo pai aqui!".
Modifique o programa acima para que o processo pai espere o processo filho terminar usando a função wait(). O processo filho deve imprimir "Processo filho terminando!" antes de sair.

*/
int main(void)
{
    int id;

    id = fork();
    if (id == 0)
        printf("Processo filho criado!\n");
    else
    {
        wait(NULL);
        printf("Processo pai criado!\n");
    }
    return (0);
}