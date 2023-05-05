/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anotherExec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:43:59 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/05 13:56:53 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// execlp, execl, execle to execute a list of arguments in different formats
// execv, execv, execvpe to vector
int	main(int argc, char **argv, char *envp[])
{
	char *arr[] = {
		"ping",
		"google.com",
		NULL
	};
	char *env[] = {
		"TEST=environment variable",
		NULL;
	};
	execvpe(env);
	execvp(arr);
	execlp("ping", "ping", "google.com", NULL);
	return (0);
}
