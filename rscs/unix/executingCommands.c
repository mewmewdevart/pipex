/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executingCommands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:06:27 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/04 15:23:03 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/* execlp commands work like:  execute a file
 *	execlp("mkdir", "mkdir", "folderName", NULL);
 */
int	main(int argc, char **argv)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
		printf("# The execlp replace everything in the child process! This like is not to be executed!");
	}
	else
	{
		wait(NULL);
		printf("Sucess!\n");
		printf("Some post processing goes here!\n");
	}
	return (0);
}
