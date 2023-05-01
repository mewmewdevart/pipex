#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv)
{
	// 1 + 2 + 3 = 6 (Child process)
	// 4 + 1 + 2 = 7 (Parent process)
	int arr[] = { 1, 2, 3, 4, 1, 2};
	int arrSize = sizeof(arr) / sizeof(int); //Saber o tamanho do array de inteiros
	int start, end;
	int fd[2];
	int id;
	int sum;
	int i;

	if (pipe(fd) == -1)
		return (1);
	
	id = fork();	
	if (id == -1)
		return (2);

	if (id == 0)
	{
		start = 0;
		end = arrSize/2;
	} else {
		start = arrSize/2;
		end = arrSize;
	}

	sum = 0;
	i = start;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("Calculated partial sum: %d\n", sum);

	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	} else {
		int sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL); // wait the children process finish to do the execution
	}
	return (0);
}