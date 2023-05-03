/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:45 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/03 14:30:52 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>

#include <fcntl.h>
// Make a FIFO special file (a named pipe)
// int mkfifo(const char *pathname, mode_t mode);

int	main(int arc, char *argv[])
{
	char	*pathfile;
	int		fd;
	int		number;

	pathfile = "myfifo1";
	if (mkfifo(pathfile, 0777) == -1)
	{
		if (errno != EEXIST)
		{
			printf("Could not create fifo file!\n");
			return (1);
		}
	}
	fd = 0;
	number = 97;
	printf("Opening...\n");
	fd = open(pathfile, O_WRONLY); // O_WRONLY : wait for write and RDONLY just read
	printf("Opened!\n1");
	if (write(fd, &number, sizeof(number)) == -1)
		return (2);
	printf("Written...\n");
	close(fd);
	printf("Closed!\n");
	return (0);
}
