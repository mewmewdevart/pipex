#include <stdio.h>
#include <stdlib.h>
/*
    void *malloc(size_t size);
    void free(void *ptr);
    void *calloc(size_t nmemb, size_t size);
    void *realloc(void *ptr, size_t size);
 */
int main (void)
{
    int *array;
    int i;

    // O retorno de malloc é do tipo void, é necessaria fazer um casting
    array = (int *)malloc(10 * sizeof(int)); // alocando
    // O tamanho de 10 * sizeof(int) é o número de bytes necessários para armazenar 
    // 10 elementos do tipo int em sequência na memória.
    // O tamanho depende do tamanho em bytes de um inteiro no sistema em que o código está sendo executado.

    i = 0;
    while(i < 10)
    {
        array[i] = i; //Inicializa o array com um valor
        i++;
    }

    i = 0;
    while(i < 10)
    {
        printf("%d\n", array[i]);
        i++;
    }
    free(array);
    return (0);
}
