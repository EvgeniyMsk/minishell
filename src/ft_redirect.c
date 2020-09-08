/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:16 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 21:21:51 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_translate(t_command *cmds)
{
	int	total;
	int	i;
	int	fd[2];

	total = 0;
	i = 0;
	while (cmds[total].cmd)
		total++;
	while (i < total)
	{
		if (i)
		{
			pipe(fd);
			ft_re_output(cmds[i - 1].out, fd[1]);
			cmds[i].in = fd[0];
		}
		if (i == total - 1)
		{
			ft_re_output(cmds[i].out, 1);
		}
		ft_re_output(cmds[i].out, -1);
		i++;
	}
}

void	ft_re_output(int *fds, int fd)
{
	int	i;

	i = 0;
	while (fds[i] != -1)
		i++;
	fds[i] = fd;
}

void	redirect(t_command cmd)
{
	int	i;

	i = 0;
	if (cmd.in != 0)
		dup2(cmd.in, 0);
	while (cmd.out[i] != -1)
	{
		if (cmd.out[i] != 1)
			dup2(cmd.out[i], 1);
		i++;
	}
}
