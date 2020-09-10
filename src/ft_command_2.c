/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:28 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/10 02:57:10 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal	g_terminal;
int					g_flag;

static int	ft_check_sign(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (i == 0 && var[i] == '=')
			return (-1);
		if (var[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

static void	ft_cd(t_command cmd)
{
	char	*home;

	if (cmd.ac == 1)
	{
		home = get_env("HOME");
		chdir(home);
		free(home);
		g_flag = 0;
	}
	else if (cmd.ac > 2)
		g_flag = 1;
	else if (chdir(cmd.av[1]) <= -1)
		g_flag = 1;
}

static void	ft_add_export(t_command cmd)
{
	int	i;
	int	sign;

	i = 1;
	while (i < cmd.ac)
	{
		if (!(sign = ft_check_sign(cmd.av[i])))
			add_env(cmd.av[i]);
		else if (sign != 0)
			ft_printf("shell-21: export: `%s': not a valid identifier\n",
																cmd.av[i]);
		i++;
	}
}

static void	ft_unset(t_command cmd)
{
	int	i;

	i = 1;
	if (cmd.ac == 1)
		return ;
	else
		while (i < cmd.ac)
			ft_clear_env(cmd.av[i++]);
}

int			builtin_parent(t_command cmd)
{
	if (!ft_strcmp(cmd.cmd, "cd"))
	{
		ft_cd(cmd);
		if (g_flag == 1)
		{
			g_flag = 0;
			return (0);
		}
	}
	else if (!ft_strcmp(cmd.cmd, "export") && cmd.ac > 1)
		ft_add_export(cmd);
	else if (!ft_strcmp(cmd.cmd, "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp(cmd.cmd, "exit"))
		quit();
	else
		return (0);
	return (1);
}
