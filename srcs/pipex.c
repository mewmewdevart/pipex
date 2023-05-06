/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:06:10 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/06 09:06:11 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = 1;
	if (argc != 5)
		ft_errors_init(22);
	else
	{
		while (i <= 4)
		{
			// Check if you have permission to access F_OK (flag for files)
			if (access(argv[i], F_OK) != 0)
				ft_errors_init(2);
			if (i == 1 && access(argv[i], R_OK) != 0) // Permission to read
				ft_errors_init(13);
			if (i == 4 && access(argv[i], W_OK) != 0) // Permission to write
				ft_errors_init(13);
			i++;
		}
		pipex(argv, envp);
	}
	return (0);
}

// The pipex controller to calling for process's
void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	// The pipe creates a communication channel that will be used by the child process and the parent process
	if (pipe(fd) == -1)
		ft_errors_process(32);
	pid = fork();
	if (pid == -1)
		ft_errors_process(3);
	else if (pid == 0)
		ft_child_process(argv, envp, fd);
	else
	{
		// Wait for process to change the status
		if (waitpid(pid, NULL, 0) == -1)
			ft_errors_process(4);
		ft_parent_process(argv, envp, fd);
	}
	return ;
}

void ft_child_process(char** argv, char** envp, int *fd)
{
	int input_file;

	ft_printf("\nEstou no ft_child_process!\n");
	input_file = open(argv[1], O_RDONLY, 0777);
	if (input_file == -1)
		ft_errors_process(4);
	dup2(fd[0], STDOUT_FILENO);
	ft_execute_commands(argv[2], envp);
}

void ft_parent_process(char** argv, char** envp, int *fd)
{
	int output_file;

	ft_printf("\nEstou no ft_parent_process!\n");
	output_file = open(argv[4], O_WRONLY | O_APPEND | O_TRUNC , 0777);
	if (output_file == -1)
		ft_errors_process(4);
	(void)fd;
	ft_execute_commands(argv[3], envp);
}