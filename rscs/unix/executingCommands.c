/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executingCommands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:06:27 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/03 18:07:42 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int	main(int argc, char **argv)
{
	execlp("ping", "ping", "-c", "3", "google.com", NULL);
	printf("Sucess!");
	return (0);
}
