/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:45 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:16:03 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

void	ft_init_command(t_command *cmd)
{
	cmd->cmd_abs = NULL;
	cmd->in = 0;
	ft_parse(cmd);
}

int		set_mode(char *arg)
{
	if (!ft_strcmp(arg, ">"))
		g_terminal.mode = 1;
	else if (!ft_strcmp(arg, ">>"))
		g_terminal.mode = 2;
	else if (!ft_strcmp(arg, "<"))
		g_terminal.mode = 3;
	else
		return (0);
	return (1);
}

void	ft_start_output(t_command *cmd, char *arg)
{
	int	flags;
	int	fd;

	flags = g_terminal.mode == 1 ? O_RDWR | O_CREAT | O_TRUNC :
								O_RDWR | O_CREAT | O_APPEND;
	if ((fd = open(arg, flags, 0666)) < 0)
		ft_printf("shell-21: cannot create %s\n", arg);
	else
		ft_re_output(cmd->out, fd);
}

void	ft_start_input(t_command *cmd, char *arg)
{
	int	flags;
	int	fd;

	flags = O_RDONLY;
	if ((fd = open(arg, flags)) < 0)
		ft_printf("shell-21: cannot read %s\n", arg);
	cmd->in = fd;
}

void	ft_parse(t_command *cmd)
{
	int	i;

	i = -1;
	g_terminal.mode = 0;
	while (++i < cmd->ac)
	{
		if (set_mode(cmd->av[i]))
			(void)g_terminal.mode;
		else if (g_terminal.mode == 1 || g_terminal.mode == 2)
			ft_start_output(cmd, cmd->av[i]);
		else if (g_terminal.mode == 3)
			ft_start_input(cmd, cmd->av[i]);
		if (g_terminal.mode > 0)
		{
			free(cmd->av[i]);
			cmd->av[i] = NULL;
		}
	}
	i = 0;
	while (cmd->av[i])
		i++;
	cmd->ac = i;
}
