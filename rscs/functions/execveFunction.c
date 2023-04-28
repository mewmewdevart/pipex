#include <stdio.h>
#include <unistd.h>

// envp é um vetor de strings contendo as variáveis de ambiente que o programa executável precisa.
int main(int argc, char *argv[], char *envp[])
{
    char *args[] = {"ls", "-l", "-a", NULL};
    char *env[] = {NULL};

    execve("/bin/ls", args, env);
    printf("Execução do programa concluída.\n");
    return(0);
}

