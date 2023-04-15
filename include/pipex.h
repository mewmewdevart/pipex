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

# include <fcntl.h> // Read
# include <string.h> // Strerror


// --------------------- CUSTOM ERRORS MESSAGE
// Function to print initialization errors
void			ft_errors_init(int number_error);
// Function to print pipe errors
void			ft_errors_pipe(int number_error);

#endif
