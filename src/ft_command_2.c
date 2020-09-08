/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:28 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:18:51 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

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
	}
	else if (cmd.ac > 2)
		ft_printf("shell-21: cd: too many arguments\n");
	else if (chdir(cmd.av[1]) < 0)
		ft_printf("shell-21: cd: %s: no such file or directory\n", \
			cmd.av[1]);
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
		ft_cd(cmd);
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
