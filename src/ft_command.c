/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:35 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/10 01:14:43 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static void	ft_echo(t_command cmd)
{
	int	i;
	int	arg;

	i = 1;
	arg = 0;
	if (cmd.ac > 1)
	{
		while (!ft_strcmp(cmd.av[arg + 1], "-n"))
			arg++;
		i += arg;
		while (cmd.av[i])
		{
			ft_printf(cmd.av[i++]);
			if (i < cmd.ac)
				ft_printf(" ");
		}
		if (!arg)
			ft_printf("\n");
	}
	else
		ft_printf("\n");
}

static void	ft_pwd(void)
{
	char	buf[1024];

	ft_printf("%s\n", getcwd(buf, sizeof(buf)));
}

void		ft_env(t_command cmd)
{
	int	i;

	i = 0;
	if (cmd.ac == 1)
		while (g_terminal.env[i])
		{
			if (ft_strncmp(g_terminal.env[i], "?=", 2) != 0)
				ft_printf("%s\n", g_terminal.env[i]);
			i++;
		}
	else
		ft_printf("env: ‘%s’: No such file or directory\n", cmd.av[1]);
}

int			builtin(t_command cmd)
{
	if (!ft_strcmp(cmd.cmd, "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp(cmd.cmd, "pwd"))
		ft_pwd();
	else if (!ft_strcmp(cmd.cmd, "env"))
		ft_env(cmd);
	else if (!ft_strcmp(cmd.cmd, "export") && cmd.ac == 1)
		ft_print_export();
	else
		return (0);
	exit(0);
	return (1);
}
