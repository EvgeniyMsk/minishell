/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:37:54 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:37:56 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	const char	*osrc;
	size_t		n;

	osrc = src;
	n = size;
	if (n)
	{
		while (--n)
		{
			if (*src)
				*dest++ = *src++;
		}
	}
	if (n == 0)
	{
		if (size)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
