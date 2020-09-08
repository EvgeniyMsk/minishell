/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:18 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:34:20 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;
	t_list	*seq;

	if (lst && *lst && del)
	{
		cur = *lst;
		while (cur)
		{
			seq = cur->next;
			ft_lstdelone(cur, del);
			cur = seq;
		}
		*lst = NULL;
	}
}
