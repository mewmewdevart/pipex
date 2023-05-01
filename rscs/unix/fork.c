/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:43:23 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/29 20:46:44 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	/*
	fork(): creates a new process by duplicating the calling process.
		The calling process is referred to as the parent process.
		The new process is referred to as the child process. 
		
			pid_t fork(void);

		On success, the PID of the child process is returned in the parent, and 0 is returned in the child. 
		On failure, -1 is returned in the parent, no child process is created, and errno is set to indicate the error.

	# -------------- CHECK TYPES OF PROCESS

	fork(); // Generate 2 type of process if you fork again 2 * 2 if you fork again is 2 * 2 * 2

	pid_t pid;

	pid = fork();
	if (pid)
		printf("\t [ parent process ] \t: %d\n", pid);
	else
	{
		//pid = fork();
		fork();
		printf("\t [ child process ] \t: %d\n", pid);
	}
*/

	// Da para redirecionar o fork : Splitando em linhas diferentes
	int id = fork();

	if (id != 0)
	{
		fork();
		printf("It is a main process!\n");
	} 
	printf("Hello World\n");
}
