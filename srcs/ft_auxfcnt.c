/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxfcnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larcrist <larcrist@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:27:31 by larcrist          #+#    #+#             */
/*   Updated: 2023/05/13 13:27:32 by larcrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

// Extension of main checker : argv[2] and argv[3] are valid
int	ft_extension_arguments(char **argv)
{
	if (ft_strlen(argv[2]) == 0
		|| ft_strspn(argv[2], " \t\n\r") == ft_strlen(argv[2]))
		return (1);
	if (ft_strlen(argv[3]) == 0
		|| ft_strspn(argv[3], " \t\n\r") == ft_strlen(argv[3]))
		return (1);
	return (0);
}

/*
    calculates the length of the initial segment of str1,
which consists entirely of characters not in str2.
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
