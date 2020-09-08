/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:49 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:10:32 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal	g_terminal;

static t_command	parse_cmd(char *cmd)
{
	int				i;
	char			**pieces;
	t_command		res;

	i = 0;
	while (i < MAX_OUTPUTS)
		res.out[i++] = -1;
	pieces = ft_split(cmd, ' ');
	free(cmd);
	res.cmd = pieces[0];
	res.ac = 0;
	while (pieces[res.ac] != NULL)
		res.ac++;
	if (!(res.av = ft_calloc(i + 1, sizeof(char *))))
		return (res);
	i = 0;
	while (pieces[i] != NULL)
	{
		res.av[i] = pieces[i];
		decode_cmd(res.av[i++]);
	}
	free(pieces);
	res.av[i] = NULL;
	ft_init_command(&res);
	return (res);
}

static t_command	*parse_cmds_pipe(char *command, char *cmd)
{
	int				i;
	char			**pipes;
	t_command		*cmds;
	t_command		last;

	i = 0;
	last.cmd = NULL;
	pipes = ft_pipe_split(command, '|', cmd);
	if (command)
		free(command);
	while (pipes[i] != NULL)
		i++;
	if (!(cmds = ft_calloc(sizeof(t_command), i + 1)))
		return (NULL);
	i = 0;
	while (pipes[i])
	{
		cmds[i] = parse_cmd(pipes[i]);
		i++;
	}
	free(pipes);
	cmds[i] = last;
	ft_translate(cmds);
	return (cmds);
}

static void			do_parse_cmd(char **commands, char **commands_2)
{
	int				i;
	int				j;
	t_command		*cmds;

	i = 0;
	while (commands[i] != NULL)
	{
		cmds = parse_cmds_pipe(commands[i], commands_2[i]);
		i++;
		j = 0;
		while (cmds[j].cmd != NULL)
		{
			if (!ft_execute_command(cmds[j]))
				free_on_fail(cmds, &j);
			else
				j++;
		}
		free(cmds);
	}
}

void				ft_parse_input(char *input)
{
	char			**commands;
	char			**commands_2;
	char			*input_2;

	input = replace(input);
	input_2 = ft_strdup(input);
	encode_cmd(input);
	commands = ft_split(input, ';');
	commands_2 = ft_shell_split(input_2, ';');
	free(input);
	free(input_2);
	do_parse_cmd(commands, commands_2);
	free(commands);
	ft_free_array(commands_2);
}
