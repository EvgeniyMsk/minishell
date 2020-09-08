/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:41:40 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:41:42 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_view_percent(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar('%');
	count = ft_output_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ft_putchar('%');
	return (count + 1);
}
