#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
Escreva um programa que cria 3 processos filhos usando a função fork(). Cada processo filho deve imprimir seu próprio número de identificação (PID) usando a função getpid().
 O processo pai deve esperar pelos 3 processos filhos terminarem e imprimir "Processos filhos terminados!" na tela.

*/

int main(void)
{
	int i;
	int pid;

	i = 0;
	while(i < 3)
	{
		pid = fork();
		if (pid == 0)
			printf("Child process %d : %d\n", i+1, getpid());
		else if (pid < 0)
			printf("Erro ao criar processo filho!\n");
		i++;
	}
	i = 0;
	while(i < 3)
	{
		wait(NULL);
		i++;
	}
	printf("Processos filhos terminados!\n");
	return (0);
}

/*
int main(void)
{
	int id1;
	int id2;
	int id3;

	id1 = fork();
	id2 = fork();
	id3 = fork();
	if (id1 == 0)
	{
		printf("Child process 01: %d\n", getpid());
		if (id2 == 0)
		{
			printf("Child process 02: %d\n", getpid());
			if (id3 == 0)
				printf("Child process 03: %d\n", getpid());
		}
	} else
	{
		wait(NULL);
		wait(NULL);
		printf("It is a parent process!\n");
	}
	return (0);
} */