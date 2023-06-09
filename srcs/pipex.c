/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:06:10 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/11 16:52:28 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_wait_process(int *fd, int pid1, int pid2);

int	main(int argc, char **argv, char **envp)
{
	int	output_file;

	if (argc != 5)
		ft_errors_init(22);
	else if (access(argv[1], F_OK) != 0)
		ft_errors_init(2);
	else if (access(argv[1], R_OK) != 0)
		ft_errors_init(13);
	else if (ft_extension_arguments(argv) == 1)
		ft_errors_init(5);
	else
	{
		if ((access(argv[4], F_OK) != 0))
		{
			output_file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			if (output_file == -1)
				ft_errors_init(5);
			close(output_file);
		}
		if (access(argv[4], W_OK) != 0)
			ft_errors_init(13);
		pipex(argv, envp);
	}
	return (0);
}

/*
   This function is the controller for executing the pipex process.
It takes in `argv` and `envp` as parameters and manages the execution
of child and parent processes.
*/

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		ft_errors_process(32);
	pid1 = fork();
	if (pid1 == -1)
		ft_errors_process(3);
	else if (pid1 == 0)
		ft_child_process(argv, envp, fd);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			ft_errors_process(3);
		else if (pid2 == 0)
			ft_parent_process(argv, envp, fd);
		else
			ft_wait_process(fd, pid1, pid2);
	}
	return ;
}

static void	ft_wait_process(int *fd, int pid1, int pid2)
{
	close(fd[0]);
	close(fd[1]);
	if (waitpid(pid1, NULL, 0) == -1)
		ft_errors_process(4);
	if (waitpid(pid2, NULL, 0) == -1)
		ft_errors_process(4);
}

/*
	A child process function : It takes the return value of the open
function in argv[1], duplicates the file descriptor using dup2 to
redirect the input and output, and to calls the execute function
*/
void	ft_child_process(char **argv, char **envp, int *fd)
{
	int	input_file;

	input_file = open(argv[1], O_RDONLY, 0777);
	if (input_file == -1)
		ft_errors_process(4);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		close(fd[1]);
		ft_errors_process(4);
	}
	if (dup2(input_file, STDIN_FILENO) == -1)
	{
		close(input_file);
		ft_errors_process(4);
	}
	close(fd[0]);
	close(input_file);
	ft_execute_commands(argv[2], envp);
}

/*
		A parent process function: It opens the output file
specified in argv[4] and duplicates the file descriptors using dup2
to redirect the input and output. Then, it calls the execute function
*/
void	ft_parent_process(char **argv, char **envp, int *fd)
{
	int	output_file;

	output_file = open(argv[4], O_WRONLY | O_TRUNC, 0777);
	if (output_file == -1)
		ft_errors_process(4);
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		close(fd[0]);
		ft_errors_process(4);
	}
	if (dup2(output_file, STDOUT_FILENO) == -1)
	{
		close(output_file);
		ft_errors_process(4);
	}
	close(fd[1]);
	close(fd[output_file]);
	ft_execute_commands(argv[3], envp);
}
