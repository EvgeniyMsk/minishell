/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:41:11 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:41:12 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_hex(char *hex, t_flags flags, size_t len)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_output_width(flags.dot - 1, len - 1, 1);
	count += ft_putstr(hex, len);
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	const size_t	len = ft_strlen(hex);
	int				count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output_hex(hex, flags, len);
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
		count += ft_output_hex(hex, flags, len);
	return (count);
}

int			ft_view_hex(unsigned int nbr, int lower, t_flags flags)
{
	char	*hex;
	int		count;

	count = 0;
	if (flags.dot == 0 && nbr == 0)
	{
		count += ft_output_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_uns_itoa_base((unsigned long long)nbr, 16);
	if (lower == 1)
		hex = ft_str_tolower(hex);
	count += ft_put_hex(hex, flags);
	free(hex);
	return (count);
}
