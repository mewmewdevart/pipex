/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 13:20:14 by larcrist          #+#    #+#             */
/*   Updated: 2023/04/15 13:20:16 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv)
{
	if (argc != 5)
		ft_errors_init(22);
	else
	{
		int i;

		i = 0;
		while(argv[i])
		{
			ft_printf("%s\n", argv[i]);
			i++;
		}
	}
	return (0);
}
