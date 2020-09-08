/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:20 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:07:30 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static char	*new_str(char *str, char *key, int a, int b)
{
	char	*res_tmp;
	char	*res;
	char	*value;
	char	*tmp[2];

	value = get_env(key);
	tmp[0] = ft_substr(str, 0, a);
	tmp[1] = ft_substr(str, b, ft_strlen(str) - b);
	res_tmp = ft_strjoin(tmp[0], value);
	res = ft_strjoin(res_tmp, tmp[1]);
	free(res_tmp);
	free(value);
	free(tmp[0]);
	free(tmp[1]);
	free(str);
	return (res);
}

static char	*do_filter_nonexistent(char **split, char *res[3], int q)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j] && (split[i][j] != '$' || q != 0))
		{
			if (split[i][j] == '\'' && q != 0)
				q--;
			j++;
		}
		res[1] = ft_substr(split[i], 0, j);
		res[2] = ft_strjoin(res[0], res[1]);
		free(res[0]);
		res[0] = ft_strjoin(res[2], " ");
		free(res[1]);
		free(res[2]);
		i++;
	}
	return (res[0]);
}

static char	*filter_nonexistent(char *str)
{
	char	**split;
	char	*res[3];
	int		i;
	int		q;

	i = 0;
	q = 0;
	while (str[i++])
		if (str[i] == '\'')
			q++;
	split = ft_split(str, ' ');
	res[0] = ft_strjoin("", "");
	res[0] = do_filter_nonexistent(split, res, q);
	free(str);
	ft_free_array(split);
	return (res[0]);
}

static char	*do_replace(char *str, char *key, char **split)
{
	t_quote	q;
	int		j;

	q.q = 0;
	q.dq = 0;
	q.f_q = 0;
	q.f_dq = 0;
	j = -1;
	while (str[++j])
	{
		str[j] == '\'' ? q.q++ : q.q;
		str[j] == '\'' && q.dq == 0 && q.q == 1 ? q.f_q++ : q.f_q;
		str[j] == '"' ? q.dq++ : q.dq;
		str[j] == '"' && q.q == 0 && q.dq == 1 ? q.f_dq++ : q.f_dq;
		if (str[j] == '~' && !q.q && !q.dq)
			str = new_str(str, "HOME", j, j + ft_strlen(key));
		if (!ft_strncmp((str + j), key, ft_strlen(key)) &&
								(!q.q || q.dq) && (!q.f_q || q.f_dq))
			str = new_str(str, split[0], j, j + ft_strlen(key));
		q.q == 2 ? q.f_q = 0 : q.f_q;
		q.q == 2 ? q.q = 0 : q.q;
		q.dq == 2 ? q.f_dq = 0 : q.f_dq;
		q.dq == 2 ? q.dq = 0 : q.dq;
	}
	return (str);
}

char		*replace(char *str)
{
	int		i;
	char	**split;
	char	*key;

	i = 0;
	while (g_terminal.env[i])
	{
		split = ft_split(g_terminal.env[i], '=');
		key = ft_strjoin("$", split[0]);
		str = do_replace(str, key, split);
		free(key);
		ft_free_array(split);
		i++;
	}
	return (filter_nonexistent(str));
}
