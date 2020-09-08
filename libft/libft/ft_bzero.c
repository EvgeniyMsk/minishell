/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:32:41 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:32:43 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;

	if (!str)
		return ;
	ptr = (unsigned char *)str;
	while (len--)
		*ptr++ = '\0';
}
