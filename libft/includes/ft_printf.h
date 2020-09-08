/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:29:27 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:29:28 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	int				type;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}					t_flags;

int					ft_printf(const char *input_str, ...);
int					ft_view_input(const char *input, va_list av);
int					ft_flag_scan(const char *input, int i, t_flags *flags,
								va_list av);

int					ft_spreader(int c, t_flags flags, va_list av);
int					ft_type(int c);
int					ft_flags(int c);

int					ft_view_char(char c, t_flags flags);
int					ft_view_hex(unsigned int nbr, int lower, t_flags flags);
int					ft_view_int(int nbr, t_flags flags);
int					ft_view_percent(t_flags flags);
int					ft_view_ptr(unsigned long long nbr, t_flags flags);
int					ft_view_str(char *str, t_flags flags);
int					ft_view_uint(unsigned int nbr, t_flags flags);

int					ft_putchar(int c);
int					ft_putstr(char *str, int len);
int					ft_output_width(int width, int minus, int zero);

char				*ft_uns_itoa(unsigned int n);
char				*ft_uns_itoa_base(unsigned long long nbr, int base);
char				*ft_str_tolower(char *str);

t_flags				ft_flag_width(t_flags flags, va_list av);
t_flags				ft_flag_minus(t_flags flags);
t_flags				ft_flag_digit(char c, t_flags flags);
int					ft_flag_dot(const char *input, int start, t_flags *flags,
								va_list av);

#endif
