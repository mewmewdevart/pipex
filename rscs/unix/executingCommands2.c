/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executingCommands2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:06:27 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/04 16:32:08 by larcrist         ###   ########.fr       */
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
	int	err;
	int	wstatus;
	int	statusCode;

	pid = fork();
	if (pid == 0)
	{
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
			return (0);
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			statusCode = WIFEXITED(swatus);
			if(statusCode == 0) //0 is sucess
				printf("Sucess!\n");
			else
				printf("Failed in the status code %d!\n", statusCode);
		} 
		printf("Some post processing goes here!\n");
	}
	return (0);
}
