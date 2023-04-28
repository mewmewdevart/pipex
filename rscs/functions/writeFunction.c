#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (void)
{
    int len;
    size_t result;
    char str[100] = "larissa";
    // ssize_t write(int fd, const void *buf, size_t count);
    
    len = strlen(str);
    result = write (1, &str, len);
    if (result == -1)
    {
        printf("Falha de leitura do arquivo.");
        return (1);
    }
    return (0);
}
