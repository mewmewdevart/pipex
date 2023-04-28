#include <unistd.h>
#include <stdio.h>

int main(void)
{
	/*
		F_OK: Verifica se o arquivo ou diretório existe.
		R_OK: Verifica se o arquivo ou diretório tem permissão de leitura.
		W_OK: Verifica se o arquivo ou diretório tem permissão de escrita.
		X_OK: Verifica se o arquivo ou diretório tem permissão de execução.
	 */
	if (access("larissa.txt", F_OK) != -1)
	{
		printf("O arquivo existe!");
		if (access("larissa.txt", X_OK) != -1)
			printf("Tem permissao de execução.");
		else
			printf("Nao tem permissao de execução");
	}
	else
		printf("O arquivo nao existe!");
	return (0);
}
