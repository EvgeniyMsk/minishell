/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_checker_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:54:07 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 21:21:27 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_start_check(char *input, char *input_2)
{
	char	*input_3;
	char	*input_fix;

	input_fix = ft_strdup(input);
	if (input_2 != NULL)
	{
		input_3 = ft_strjoin("| ", input_2);
		free(input_2);
		input_2 = ft_strjoin(input_fix, input_3);
		free(input_3);
		free(input_fix);
	}
	return (input_2 != NULL ? input_2 : input_fix);
}

char		*ft_check_input_2(char *input)
{
	char	*input_2;
	int		i;

	i = -1;
	input_2 = NULL;
	while (input[++i])
	{
		if ((input[i] == '|' || input[i] == ';') && input[i + 1] == '\0')
		{
			if (input[i] == '|')
			{
				ft_printf("> ");
				ft_read_command(&input_2);
			}
			input[i] = ' ';
			break ;
		}
	}
	return (ft_start_check(input, input_2));
}
