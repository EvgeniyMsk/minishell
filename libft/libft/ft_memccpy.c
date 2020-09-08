/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:35:25 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:35:26 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		sym;
	unsigned char		*ptr_1;
	const unsigned char	*ptr_2;

	sym = (unsigned char)c;
	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	while (n--)
	{
		*ptr_1++ = *ptr_2++;
		if (*(ptr_1 - 1) == sym)
			return (ptr_1);
	}
	return (NULL);
}
