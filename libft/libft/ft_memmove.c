/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:35:55 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:36:00 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_1;
	unsigned char	*ptr_2;

	ptr_1 = (unsigned char *)dest;
	ptr_2 = (unsigned char *)src;
	if (!ptr_1 && !ptr_2)
		return (dest);
	if (ptr_1 < ptr_2)
		while (n--)
			*ptr_1++ = *ptr_2++;
	else
		while (n--)
			ptr_1[n] = ptr_2[n];
	return (dest);
}
