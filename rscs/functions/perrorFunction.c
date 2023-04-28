#include <stdio.h>
#include <errno.h>

int main(void)
{
    FILE *fp;
    char *pathfile = "file.tx";

    fp = fopen(pathfile, "r");
    if (fp == NULL)
        perror("Erro ao abrir o arquivo!");

    //void perror(const char *s);
    return (0);
}
