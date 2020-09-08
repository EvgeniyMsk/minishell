/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:55:27 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/09 01:06:56 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_terminal g_terminal;

static t_list	*sort_env(void)
{
	t_list	*start;
	t_var	*var1;
	t_var	*var2;
	void	*swap;
	int		size;

	size = ft_lstsize(g_terminal.exp);
	start = g_terminal.exp;
	while (size--)
	{
		g_terminal.exp = start;
		while (g_terminal.exp->next)
		{
			var1 = (t_var*)g_terminal.exp->content;
			var2 = (t_var*)g_terminal.exp->next->content;
			if (ft_strcmp(var1->key, var2->key) > 0)
			{
				swap = g_terminal.exp->content;
				g_terminal.exp->content = g_terminal.exp->next->content;
				g_terminal.exp->next->content = swap;
			}
			g_terminal.exp = g_terminal.exp->next;
		}
	}
	return (start);
}

static t_var	*create_var(char *env)
{
	size_t	i;
	t_var	*var;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	if (i == ft_strlen(env))
		return (NULL);
	if (!(var = (t_var *)malloc(sizeof(t_var))))
		return (NULL);
	var->key = ft_substr(env, 0, i);
	var->value = ft_substr(env, i + 1, ft_strlen(env) - i - 1);
	return (var);
}

/*
**	Copy env to list
*/

static void		copy_env_export(void)
{
	int		i;
	t_var	*tmp;
	t_list	*new;

	i = 0;
	while (g_terminal.env[i])
	{
		tmp = create_var(g_terminal.env[i]);
		if (!(new = ft_lstnew(tmp)))
			free(tmp);
		ft_lstadd_back(&g_terminal.exp, new);
		i++;
	}
}

static void		print_export(void *element)
{
	t_var		*var;

	var = (t_var*)element;
	if ((var->key[0] == '_' && var->key[1] == '\0') || var->key[0] == '?')
		return ;
	ft_printf("declare -x %s=\"%s\"\n", var->key, var->value);
}

void			ft_print_export(void)
{
	copy_env_export();
	g_terminal.exp = sort_env();
	ft_lstiter(g_terminal.exp, print_export);
	ft_lstclear(&g_terminal.exp, &ft_clear_var);
}
