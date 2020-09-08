/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:08 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:03:36 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static char	*ft_make_my_bash(char *dir)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (dir[i])
	{
		if (dir[i] != '/')
			count++;
		while (dir[i] != '/' && dir[i + 1])
			i++;
		i++;
	}
	i = 0;
	if (count < 2)
		return (ft_strdup(dir));
	else if (count == 2)
		return (ft_strdup("~"));
	while (*dir && i != 3)
		if (*dir++ == '/')
			i++;
	dir--;
	return (ft_strjoin("~", dir));
}

void		ft_show_term(void)
{
	char	cwd[1024];
	char	*dir;

	dir = ft_make_my_bash(getcwd(cwd, sizeof(cwd)));
	ft_printf("shell-21$:");
	free(dir);
}

void		ft_read_command(char **line)
{
	int		i;
	char	buf[1];

	i = get_next_line(0, line);
	if (!i && !ft_strlen(*line))
	{
		free(*line);
		quit();
	}
	while (!i)
		i = read(0, buf, 1);
}

void		ft_minishell(void)
{
	char	*input;
	char	*trim_input;
	int		ret;

	ret = 0;
	input = NULL;
	while (1)
	{
		ft_show_term();
		ft_handle_signals();
		ft_read_command(&input);
		trim_input = ft_strtrim(input, " ");
		free(input);
		if (ft_check_input(trim_input) == 0)
			ft_parse_input(ft_check_input_2(trim_input));
		if (trim_input)
			free(trim_input);
	}
}
