/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:18 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/10 03:02:02 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal	g_terminal;
extern int			g_flag;

void		ft_initialize(int n)
{
	char	*nb;
	char	*res;

	nb = ft_itoa(n);
	g_terminal.status = n;
	res = ft_strjoin("?=", nb);
	add_env(res);
	free(res);
	free(nb);
}

static void	exec_on_child(t_command cmd)
{
	int	exec_res;

	redirect(cmd);
	if (!builtin(cmd))
	{
		if (cmd.in < 0)
			exit(1);
		cmd.cmd_abs = get_path(cmd.cmd);
		if (cmd.cmd_abs == NULL)
		{
			ft_printf("shell-21: %s: command not found\n", cmd.cmd);
			exit(127);
		}
		exec_res = execve(cmd.cmd_abs, cmd.av, g_terminal.env);
		if (exec_res < 0)
		{
			ft_printf("shell-21: %s: command not found\n", cmd.cmd);
			exit(127);
		}
	}
}

static void	ft_support(pid_t pid)
{
	g_terminal.pid = pid;
	wait(&pid);
	if (g_flag == 1)
	{
		g_flag = 0;
		ft_initialize(1);
	}
	else
		ft_initialize(WEXITSTATUS(pid));
	g_terminal.pid = 0;
}

int			ft_execute_command(t_command cmd)
{
	pid_t	pid;

	if (builtin_parent(cmd))
	{
		free_cmd(cmd);
		return (1);
	}
	pid = fork();
	if (!pid)
		exec_on_child(cmd);
	else if (pid < 0)
	{
		ft_printf("shell-21: fork error\n");
		exit(127);
	}
	else
		ft_support(pid);
	close_fd(cmd);
	free_cmd(cmd);
	return (g_terminal.status == 0);
}
