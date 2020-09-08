/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:40:32 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:40:41 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags			ft_init_flags(void)
{
	t_flags		flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int				ft_flag_scan(const char *input, int i, t_flags *flags,
								va_list av)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_type(input[i]) && !ft_flags(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, av);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(*flags, av);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_type(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		i++;
	}
	return (i);
}

int				ft_view_input(const char *input, va_list av)
{
	int			i;
	t_flags		flags;
	int			count;

	count = 0;
	i = 0;
	while (input[i])
	{
		flags = ft_init_flags();
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			i = ft_flag_scan(input, i, &flags, av);
			if (ft_type(input[i]))
				count += ft_spreader((char)flags.type, flags, av);
			else if (input[i])
				count += ft_putchar(input[i]);
		}
		else if (input[i] != '%')
			count += ft_putchar(input[i]);
		i++;
	}
	return (count);
}

int				ft_printf(const char *input_str, ...)
{
	const char	*input;
	va_list		av;
	int			count;

	count = 0;
	if (!(input = ft_strdup(input_str)))
		return (-1);
	va_start(av, input_str);
	count += ft_view_input(input, av);
	va_end(av);
	free((char *)input);
	return (count);
}
