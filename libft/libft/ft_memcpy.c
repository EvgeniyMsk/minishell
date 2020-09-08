/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:35:51 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:35:52 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_1;
	const unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	if (!ptr_1 && !ptr_2)
		return (dest);
	while (n--)
		*ptr_1++ = *ptr_2++;
	return (dest);
}
