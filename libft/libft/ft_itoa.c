/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:33:50 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:33:52 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_nbrlen(int nbr, int base)
{
	size_t	len;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_nbrlen(n, 10);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
	}
	while (i < size--)
	{
		str[size] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
