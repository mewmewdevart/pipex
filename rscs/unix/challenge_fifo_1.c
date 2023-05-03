/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   challenge_fifo_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:37 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/03 14:49:45 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int	main(void)
{
	char *pathname = "makezinho";
	int fd;

	// Criação do fifo
	mkfifo(pathname, 0777); // 0777 : permissão de leitura, gravação e execução.
	
	// Abertura o FIFO em modo de leitura
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
		return (1);

	// Imprime o descritor do arquivo FIFO
	printf("O descritor de arquivo FIFO é: %d", fd);

	close(fd);
	return (0);
}
