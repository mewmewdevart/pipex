/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:13:46 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/15 13:13:49 by larcrist         ###   ########.fr       */
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

// --------------------- CUSTOM ERRORS MESSAGE
// The pipex controller to calling for process's
void            pipex(char **argv, char **envp);
// Function to print initialization errors
void			ft_errors_init(int number_error);
// Function to print process errors
void            ft_errors_process(int number_error);

void			ft_child_process(char **argv, char **envp, int *fd);
void			ft_parent_process(char **argv, char **envp, int *fd);

void ft_execute_commands(char *argv, char **envp);

#endif
