/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:41:18 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:41:19 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_int(char *nbr_str, int nbr_tmp, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (nbr_tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_output_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr(nbr_str, len);
	return (count);
}

static int	ft_put_int(char *nbr_str, int nbr_tmp, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output_int(nbr_str, nbr_tmp, flags, len);
	if (flags.dot >= 0 && (size_t)flags.dot < len)
		flags.dot = len;
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_output_width(flags.width, 0, 0);
	}
	else
		count += ft_output_width(flags.width, len, flags.zero);
	if (flags.minus == 0)
		count += ft_output_int(nbr_str, nbr_tmp, flags, len);
	return (count);
}

int			ft_view_int(int nbr, t_flags flags)
{
	char	*nbr_str;
	int		nbr_tmp;
	int		count;

	count = 0;
	nbr_tmp = nbr;
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_output_width(flags.width, 0, 0);
		return (count);
	}
	if (nbr < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			ft_putchar('-');
		nbr *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	nbr_str = ft_itoa(nbr);
	count += ft_put_int(nbr_str, nbr_tmp, flags);
	free(nbr_str);
	return (count);
}
