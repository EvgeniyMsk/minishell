/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:12 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:07:21 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

void	quit(void)
{
	ft_free_array(g_terminal.env);
	ft_printf("exit\n");
	exit(0);
}

void	ft_clear_var(void *element)
{
	t_var	*tmp;

	tmp = (t_var *)element;
	if (tmp->key)
		free(tmp->key);
	if (tmp->value)
		free(tmp->value);
	if (tmp)
		free(tmp);
}

void	free_cmd(t_command cmd)
{
	int	i;

	i = 0;
	while (cmd.av[i])
		free(cmd.av[i++]);
	free(cmd.av);
	free(cmd.cmd_abs);
}

void	free_on_fail(t_command *cmds, int *j)
{
	(*j)++;
	while (cmds[*j].cmd)
		free_cmd(cmds[(*j)++]);
}

void	close_fd(t_command cmd)
{
	int	i;

	i = 0;
	if (cmd.in != 0)
		close(cmd.in);
	while (cmd.out[i] != -1)
	{
		if (cmd.out[i] != 1)
			close(cmd.out[i]);
		i++;
	}
}
