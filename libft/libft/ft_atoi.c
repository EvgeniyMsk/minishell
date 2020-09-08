/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:32:34 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:32:35 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	unsigned long long	res;
	int					sign;
	size_t				count;

	res = 0;
	sign = 1;
	count = 0;
	while (*nptr == '\n' || *nptr == ' ' || *nptr == '\t' ||
			*nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr && *nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
		count++;
	}
	if (res > 9223372036854775807 || count > 19)
		return ((sign == -1) ? 0 : -1);
	return ((int)res * sign);
}
