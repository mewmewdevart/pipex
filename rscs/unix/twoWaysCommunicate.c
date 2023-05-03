/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twoWaysCommunicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:09:28 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/03 17:27:23 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int	main(int argc, char **argv)
{
	int	p1[2];
	int	pid;
	int	x;
	int	y;

	if (pipe(p1) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0) //Child process
	{
		if (read(p1[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Received %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Wrote %d\n", x);
	}
	else //Father process
	{
		srand(time(NULL));
		y = rand() % 100;
		if (write(p1[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Wrote %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result is %d\n", y);
		wait(NULL);

	}
	close(p1[0]);
	close(p1[1]);
	return (0);

}
