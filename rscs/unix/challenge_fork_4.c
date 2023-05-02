#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
/*
Crie um programa que utilize a função fork() para criar dois processos filhos. Cada filho deve imprimir seu próprio PID e o PID do outro filho. O processo pai deve aguardar os dois processos filhos terminarem e, em seguida, imprimir uma mensagem de "tchau".

*/
int main(void)
{
	int id1;
	int id2;
	pid_t pid1;
	pid_t pid2;

	id1 = fork();
	if (id1 == 0)
	{
		pid1 = getpid();
		printf("Child 01 process: %d\n", getpid());
		id2 = fork();
		if (id2 == 0)
		{
			pid2 = getpid();
			printf("Child 02 process: %d\n", getpid());
			printf("Child 01 process in Child 02: %d\n", pid1);
		}
		if (id1 == 0 && id2 == 0)
			printf("Child 02 process in Child 01: %d\n", pid2);

	} else {
		wait(NULL);
		printf("Tchau!\n");
	}
	return (0);
}