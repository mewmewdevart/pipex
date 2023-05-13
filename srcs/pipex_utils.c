/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:33:25 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/11 16:52:41 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	ft_execute_other_command(char **commands, char **envp);
static char	*ft_search_directories(char *command, char **envp);
static char	**ft_get_directories(char **envp);

/*
	Executes specified commands, splitting and executing them
separately. Useful for handling multiple commands in a single call
*/
void	ft_execute_commands(char *argv, char **envp)
{
	char	**commands;
	char	*path;
	int		i;

	commands = ft_split(argv, ' ');
	if (commands[0] != NULL)
	{
		path = ft_correct_path(commands[0], envp);
		if (path)
		{
			if (execve(path, commands, envp) == -1)
				ft_errors_process(3);
		}
		else
			ft_execute_other_command(commands, envp);
	}
	else
		write(2, "\nError\nNo commands specified!", 30);
	i = 0;
	while (commands[i] != NULL)
		free(commands[i++]);
	free(commands);
}

/*
	Executes a second specified command when the first one is not found.
Useful for handling scenarios where an alternative command should be
executed if the first one is unavailable.
*/
static void	ft_execute_other_command(char **commands, char **envp)
{
	char	*path;

	if (commands[1] != NULL)
	{
		path = ft_correct_path(commands[1], envp);
		if (path)
		{
			if (execve(path, commands + 1, envp) == -1)
				ft_errors_process(3);
		}
		else
			write(2, "\nError\nSecond command not found!", 32);
	}
	else
		write(2, "\nError\nNo second command specified!", 36);
}

/*
	Corrects the path of a command by checking if it's an absolute
or relative path. Useful for take the correct path to execute a command
*/
char	*ft_correct_path(char *command, char **envp)
{
	if (command[0] == '/' || command[0] == '.')
	{
		if (access(command, F_OK) == 0)
			return (ft_strdup(command));
		return (NULL);
	}
	return (ft_search_directories(command, envp));
}

/*
	Searches for a command in specific directories based on
environment variables. Useful for locating the correct path
of a command based on environment settings
*/
static char	*ft_search_directories(char *command, char **envp)
{
	char	*path;
	char	*half_path;
	char	**directories;
	int		i;

	i = 0;
	directories = ft_get_directories(envp);
	while (directories[i])
	{
		half_path = ft_strjoin(directories[i], "/");
		path = ft_strjoin(half_path, command);
		free(half_path);
		if (access(path, F_OK) == 0)
		{
			free(directories);
			return (path);
		}
		free(path);
		i++;
	}
	i = -1;
	while (directories[++i])
		free(directories[i]);
	free(directories);
	return (NULL);
}

/*
	Retrieves directories relevant for command lookup based
on provided environment variables (envp). Useful for extracting
directories from the "PATH" variable in the command search operations
*/
static char	**ft_get_directories(char **envp)
{
	char	**directories;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == NULL)
		i++;
	directories = ft_split(envp[i] + 5, ':');
	return (directories);
}
