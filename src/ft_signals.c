/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:29 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:07:40 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static void	handle_ctrl_c(int signal)
{
	ft_printf("\n");
	if (!g_terminal.pid)
		ft_show_term();
	else
		kill(g_terminal.pid, signal);
}

static void	handle_ctrl_backslash(int signal)
{
	if (g_terminal.pid)
	{
		kill(g_terminal.pid, signal);
		ft_printf("Quit (core dumped)\n");
	}
}

void		ft_handle_signals(void)
{
	if (signal(SIGINT, &handle_ctrl_c) == SIG_ERR)
		ft_printf("Could not set SIGINT handler\n");
	if (signal(SIGQUIT, &handle_ctrl_backslash) == SIG_ERR)
		ft_printf("Could not set SIGQUIT handler\n");
}
