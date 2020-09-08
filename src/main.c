/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:38 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:08:08 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_terminal g_terminal;

int	main(int ac, char **av, char **env)
{
	g_terminal.env = copy_env(env);
	ft_initialize(0);
	ft_minishell();
	return (0);
}
