/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:56:02 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 21:21:39 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_k;
int g_i;

static int		ft_free(char **str, int size)
{
	int	i;

	i = 0;
	while (size > i)
		free(str[i++]);
	free(str);
	return (-1);
}

static size_t	ft_countw(const char *s, char c, char *cmd)
{
	size_t	i;
	size_t	count;
	int		q;
	int		dq;

	q = 0;
	dq = 0;
	i = -1;
	count = 0;
	while (s[++i])
	{
		cmd[i] == '\'' ? q++ : q;
		cmd[i] == '"' ? dq++ : dq;
		if (s[i] != c || (q || dq))
			count++;
		while ((s[i] != c || (q || dq)) && s[i + 1])
		{
			cmd[i] == '\'' ? q++ : q;
			cmd[i] == '"' ? dq++ : dq;
			q == 2 ? q = 0 : q;
			dq == 2 ? dq = 0 : dq;
			i++;
		}
	}
	return (count);
}

static size_t	ft_lenw(const char *s, char c, char *cmd)
{
	size_t	i;
	size_t	len;
	int		q;
	int		dq;

	q = 0;
	dq = 0;
	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while ((s[i] != c || (q || dq)) && s[i])
	{
		cmd[i] == '\'' ? q++ : q;
		cmd[i] == '"' ? dq++ : dq;
		q == 2 ? q = 0 : q;
		dq == 2 ? dq = 0 : dq;
		len++;
		i++;
	}
	return (len);
}

static int		ft_start_splitter(char **str, char const *s, char c, char *cmd)
{
	size_t	j;
	int		q;
	int		dq;

	q = 0;
	dq = 0;
	if (!(str[g_i] = (char *)malloc(sizeof(char) *
											(ft_lenw(&s[g_k], c, cmd) + 1))))
		return (ft_free(str, g_k));
	j = 0;
	while (s[g_k] == c)
		g_k++;
	while ((s[g_k] != c || (q || dq)) && s[g_k])
	{
		cmd[g_k] == '\'' ? q++ : q;
		cmd[g_k] == '"' ? dq++ : dq;
		q == 2 ? q = 0 : q;
		dq == 2 ? dq = 0 : dq;
		str[g_i][j++] = s[g_k++];
	}
	str[g_i++][j] = '\0';
	return (0);
}

char			**ft_pipe_split(char const *s, char c, char *cmd)
{
	char			**str;
	const size_t	countw = ft_countw(s, c, cmd);

	g_k = 0;
	g_i = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (countw + 1))))
		return (NULL);
	while (g_i < countw)
		if (ft_start_splitter(str, s, c, cmd) == -1)
			return (NULL);
	str[g_i] = NULL;
	return (str);
}
