/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:41:59 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:42:00 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_uint(char *nbr_str, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_output_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr(nbr_str, len);
	return (count);
}

static int	ft_put_uint(char *nbr_str, t_flags flags)
{
	const size_t	len = ft_strlen(nbr_str);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output_uint(nbr_str, flags, len);
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
		count += ft_output_uint(nbr_str, flags, len);
	return (count);
}

int			ft_view_uint(unsigned int nbr, t_flags flags)
{
	char	*nbr_str;
	int		count;

	count = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_output_width(flags.width, 0, 0);
		return (count);
	}
	nbr_str = ft_uns_itoa_base(nbr, 10);
	count += ft_put_uint(nbr_str, flags);
	free(nbr_str);
	return (count);
}
