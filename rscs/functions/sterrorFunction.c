#include <stdio.h>
#include <string.h>

 
int main (void)
{
	int number_error = 1; // Operation not permitted 
		       // https://www.thegeekstuff.com/2010/10/linux-error-codes/
	// char *strerror(int errnum);
	printf("%s", strerror(number_error));
	return (0);
}
