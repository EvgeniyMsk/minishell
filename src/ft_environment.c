/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:50 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:05:47 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static int	get_env_index(char *var)
{
	int		i;
	char	*key;

	i = 0;
	if (!(key = (char *)ft_calloc(sizeof(char), ft_strlen(var) + 2)))
		return (0);
	ft_strcat(key, var);
	ft_strcat(key, "=");
	while (g_terminal.env[i])
	{
		if (!ft_strncmp(g_terminal.env[i], key, ft_strlen(key)))
		{
			free(key);
			return (i);
		}
		++i;
	}
	free(key);
	return (-1);
}

char		*get_path(char *cmd)
{
	char		**paths;
	struct stat	buf;
	char		*file_name[2];
	int			i;

	i = -1;
	if (!stat(cmd, &buf))
		return (ft_strjoin(cmd, ""));
	if ((file_name[1] = get_env("PATH")) == NULL)
		return (NULL);
	paths = ft_split(file_name[1], ':');
	while (paths[++i])
	{
		ft_create(paths[i], cmd, file_name);
		if (!stat(file_name[0], &buf))
		{
			free(file_name[1]);
			ft_free_array(paths);
			return (file_name[0]);
		}
		free(file_name[0]);
	}
	free(file_name[1]);
	ft_free_array(paths);
	return (NULL);
}

char		*get_env(char *var)
{
	char	**env;
	char	**res;
	char	*key;
	char	*tmp;

	env = g_terminal.env;
	if (!(key = (char *)ft_calloc(sizeof(char), ft_strlen(var) + 2)))
		return (NULL);
	ft_strcat(key, var);
	ft_strcat(key, "=");
	while (*env)
	{
		if (!ft_strncmp(*env, key, ft_strlen(key)))
		{
			res = ft_split(*env, '=');
			tmp = ft_strjoin(res[1], "");
			ft_free_array(res);
			free(key);
			return (tmp);
		}
		env++;
	}
	free(key);
	return (NULL);
}

void		add_env(char *var)
{
	char	**envp;
	char	**split;
	int		i;

	i = 0;
	split = ft_split(var, '=');
	ft_clear_env(split[0]);
	ft_free_array(split);
	while (g_terminal.env[i])
		i++;
	if (!(envp = (char **)ft_calloc(sizeof(char *), i + 2)))
		return ;
	i = 0;
	while (g_terminal.env[i])
	{
		envp[i] = ft_strjoin(g_terminal.env[i], "");
		i++;
	}
	envp[i] = ft_strjoin(var, "");
	ft_free_array(g_terminal.env);
	g_terminal.env = envp;
}

void		ft_clear_env(char *var)
{
	int		i;
	int		j;
	char	**res;
	int		index;

	i = 0;
	if ((index = get_env_index(var)) == -1)
		return ;
	while (g_terminal.env[i])
		i++;
	if (!(res = (char **)ft_calloc(sizeof(char *), i + 1)))
		return ;
	i = 0;
	j = 0;
	while (g_terminal.env[i])
	{
		if (i != index)
			res[j++] = ft_strjoin(g_terminal.env[i], "");
		i++;
	}
	ft_free_array(g_terminal.env);
	g_terminal.env = res;
}
