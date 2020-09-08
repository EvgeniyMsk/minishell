/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:41:52 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:41:53 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_output_str(char *str, t_flags flags, size_t len)
{
	int		count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_output_width(flags.dot, len, 0);
		count += ft_putstr(str, flags.dot);
	}
	else
		count += ft_putstr(str, len);
	return (count);
}

int			ft_view_str(char *str, t_flags flags)
{
	size_t	len;
	char	*str_1;
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	str_1 = ft_substr(str, 0, len);
	if (flags.dot >= 0 && (size_t)flags.dot > len)
		flags.dot = len;
	if (flags.minus == 1)
		count += ft_output_str(str_1, flags, len);
	if (flags.dot >= 0)
		count += ft_output_width(flags.width, flags.dot, 0);
	else
		count += ft_output_width(flags.width, len, 0);
	if (flags.minus == 0)
		count += ft_output_str(str_1, flags, len);
	free(str_1);
	return (count);
}
