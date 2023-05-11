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

static char	**ft_get_directories(char **envp);

/*
	The function splits the command string into individual arguments, 
find the correct path for the command, and attempts to execute it using execve
*/
void	ft_execute_commands(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	path = ft_correct_path(command[0], envp);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		write(2, "Error\nCommand not found!", 25);
		exit(1);
	}
	if (execve(path, command, envp) == -1)
		ft_errors_process(3);
}

/*
	This function finds the correct path for a given command by searching inside
	the directories specified in the PATH environment variable
*/
char	*ft_correct_path(char *command, char **envp)
{
	char	*path;
	char	*half_path;
	char	**directories;
	int		i;

	directories = ft_get_directories(envp);
	i = 0;
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
	return (0);
}

/*
	This function finds the directories specified in the PATH environment variable
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

/*
	The ft_strspn function is used to determine the length of the initial
segment of a string (s1) that only contains characters present in another 
string (s2).
*/
size_t	ft_strspn(const char *s1, const char *s2)
{
	size_t		count;

	count = 0;
	while (*s1)
	{
		if (ft_strchr(s2, *s1))
			count++;
		else
			break ;
		s1++;
	}
	return (count);
}
