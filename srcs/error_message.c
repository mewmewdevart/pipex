/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:20:02 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/15 13:20:03 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Function to print initialization errors
void	ft_errors_init(int number_error)
{
	if (number_error == 2)
		ft_printf("Error\nNo such file or directory.\n");
	else if (number_error == 5)
		ft_printf("Error\nInput/Output error!\n");
	else if (number_error == 13)
		ft_printf("Error\nPermission denied");
	else if (number_error == 22)
	{
		ft_printf("Error\nInvalid argument!\n");
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	exit (1);
	return ;
}

// Function to print process errors
void	ft_errors_process(int number_error)
{
	if (number_error == 4)
		ft_printf("Error\nInterrupted system call.\n");
	else if (number_error == 3)
		ft_printf("Error\nNo such process!\n");
	else if (number_error == 10)
		ft_printf("Error\nNo child processes!\n");
	else if (number_error == 11)
		ft_printf("Error\nResource temporarily unavailable!\n");
	else if (number_error == 32)
		ft_printf("Error\nBroken pipe. Pipe write error!\n");
	exit (1);
	return ;
}
