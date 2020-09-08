/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:08:19 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:08:51 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(const char *str)
{
	const char	*end;

	end = str;
	while (*end != '\0')
		++end;
	return (end - str);
}

char	*ft_strchr(const char *str, int c)
{
	c = (unsigned char)c;
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		++str;
	}
	return ((*str == c) ? (char *)str : NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char	*pdest;
	char	*psrc;

	if (dest == src)
		return (dest);
	pdest = (char *)dest;
	psrc = (char *)src;
	while (num-- != 0)
		*pdest++ = *psrc++;
	return (dest);
}

char	*ft_strdup(const char *str)
{
	size_t		block_size;
	void		*ptr;

	block_size = ft_strlen(str) + 1;
	if (!(ptr = malloc(block_size)))
		return (NULL);
	return (ft_memcpy(ptr, str, block_size));
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char		*big;
	size_t		len1;
	size_t		len2;

	if (!str1 || !str2)
		return (NULL);
	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (!(big = (char *)malloc(len1 + len2 + 1)))
		return (NULL);
	ft_memcpy(big, str1, len1);
	ft_memcpy(big + len1, str2, len2 + 1);
	return (big);
}
