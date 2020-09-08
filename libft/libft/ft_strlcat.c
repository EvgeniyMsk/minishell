/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:37:42 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:40:17 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dest;
	osrc = src;
	n = size;
	while (n-- && *dest)
		dest++;
	dlen = dest - odst;
	n = size - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dest++ = *src;
			n--;
		}
		src++;
	}
	*dest = '\0';
	return (dlen + (src - osrc));
}
