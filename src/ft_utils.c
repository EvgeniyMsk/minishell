/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:55 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:08:04 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

void	ft_handle_quote(char *c)
{
	if (!g_terminal.quote && !g_terminal.dquote)
	{
		g_terminal.quote = 1;
		*c = ' ';
	}
	else if (g_terminal.quote && !g_terminal.dquote)
	{
		g_terminal.quote = 0;
		*c = ' ';
	}
}

void	ft_handle_dquote(char *c)
{
	if (!g_terminal.quote && !g_terminal.dquote)
	{
		*c = ' ';
		g_terminal.dquote = 1;
	}
	else if (!g_terminal.quote && g_terminal.dquote)
	{
		*c = ' ';
		g_terminal.dquote = 0;
	}
}

void	ft_handle_letter(char *c)
{
	if ((g_terminal.quote || g_terminal.dquote) && *c == ' ')
		*c = 1;
	if ((g_terminal.quote || g_terminal.dquote) && *c == ';')
		*c = 2;
}

void	decode_cmd(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 1)
			str[i] = ' ';
		if (str[i] == 2)
			str[i] = ';';
	}
}

void	encode_cmd(char *cmd)
{
	int	i;

	g_terminal.quote = 0;
	g_terminal.dquote = 0;
	i = -1;
	while (cmd[++i])
	{
		if (cmd[i] == '\'')
			ft_handle_quote(&cmd[i]);
		else if (cmd[i] == '"')
			ft_handle_dquote(&cmd[i]);
		else
			ft_handle_letter(&cmd[i]);
	}
}
