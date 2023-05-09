/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:13:46 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/09 12:58:11 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libs/libft/includes/libft.h"

# include <sys/types.h> // Wait
# include <sys/wait.h> // Wait
# include <stdio.h> 
# include <unistd.h> // Write, access, fork, pid, envp
# include <fcntl.h> // Read
# include <string.h> // Strerror
# include <errno.h> // Errno

// Extension of main checker : argv[3] is not invalid
int		ft_extension_arguments(char **argv);
// This function is the controller for executing the pipex process. 
void	pipex(char **argv, char **envp);
// This function is executed by the child process.
void	ft_child_process(char **argv, char **envp, int *fd);
// This function is executed by the parent process.
void	ft_parent_process(char **argv, char **envp, int *fd);
//  This function is responsible for executing the commands.
void	ft_execute_commands(char *argv, char **envp);
//  This function finds the correct path for a given command.
char	*ft_correct_path(char *command, char **envp);
// This function is responsible for printing initialization errors.
void	ft_errors_init(int number_error);
// This function is responsible for printing process errors.
void	ft_errors_process(int number_error);

// This function check if the chars in s1 have only s2 chars
size_t	ft_strspn(const char *s1, const char *s2);

#endif
