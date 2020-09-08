/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_environment_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:41 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 21:21:04 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	int		i;
	char	**res;

	i = 0;
	while (env[i])
		i++;
	if (!(res = (char **)ft_calloc(sizeof(char *), i + 1)))
		return (NULL);
	i = 0;
	while (env[i])
	{
		res[i] = ft_strjoin(env[i], "");
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	ft_create(char *path, char *cmd, char *file_name[2])
{
	if (!(file_name[0] = (char *)ft_calloc(sizeof(char),
				(ft_strlen(cmd) + ft_strlen(path) + 2))))
		return ;
	file_name[0] = ft_strcat(file_name[0], path);
	file_name[0] = ft_strcat(file_name[0], "/");
	file_name[0] = ft_strcat(file_name[0], cmd);
}
