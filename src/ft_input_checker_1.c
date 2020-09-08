/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_checker_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:19 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:16:21 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print_error(int c, int spaces)
{
	if (c == ';')
		spaces == 0 ?
			ft_printf("shell-21: syntax error near unexpected token `;;'\n") :
			ft_printf("shell-21: syntax error near unexpected token `;'\n");
	else if (c == '|')
		spaces == 0 ?
			ft_printf("shell-21: it's bonus, don't set zero :3 `||'\n") :
			ft_printf("shell-21: syntax error near unexpected token `|'\n");
}

static int	ft_start_check(char *input, int *i, int q, int dq)
{
	int	spaces;
	int	symb;

	spaces = 0;
	symb = 0;
	if ((input[*i] == ';' || input[*i] == '|') && (!q && !dq))
	{
		while (input[++(*i)] && input[*i + 1] != '\0' &&
				(input[*i] != ';' && input[*i] != '|'))
		{
			if (input[*i] == ' ')
				spaces++;
			symb++;
		}
		if (spaces == symb)
		{
			ft_print_error(input[*i], spaces);
			ft_initialize(2);
			return (1);
		}
	}
	return (0);
}

static int	ft_check_init(char *input)
{
	if (input[0] == ';')
	{
		input[1] == ';' ?
			ft_printf("shell-21: syntax error near unexpected token `;;'\n") :
			ft_printf("shell-21: syntax error near unexpected token `;'\n");
		ft_initialize(2);
		return (1);
	}
	else if (input[0] == '|')
	{
		input[1] == '|' ?
			ft_printf("shell-21: syntax error near unexpected token `||'\n") :
			ft_printf("shell-21: syntax error near unexpected token `|'\n");
		ft_initialize(2);
		return (1);
	}
	else
		return (0);
}

int			ft_check_input(char *input)
{
	int	i;
	int	q;
	int	dq;

	i = -1;
	q = 0;
	dq = 0;
	if (ft_check_init(input) == 1)
		return (1);
	while (input[++i] && input[i + 1] != '\0')
	{
		input[i] == '\'' ? q++ : q;
		input[i] == '"' ? dq++ : dq;
		if (ft_start_check(input, &i, q, dq) == 1)
			return (1);
		q == 2 ? q = 0 : q;
		dq == 2 ? dq = 0 : dq;
	}
	return (0);
}
