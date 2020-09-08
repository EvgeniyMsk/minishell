/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qsymond <qsymond@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:34:52 by qsymond           #+#    #+#             */
/*   Updated: 2020/09/08 20:34:54 by qsymond          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur_new;
	t_list	*cur_old;

	if (!lst || !(new = ft_lstnew(f(lst->content))))
		return (NULL);
	cur_new = new;
	cur_old = lst->next;
	while (cur_old)
	{
		if (!(cur_new->next = ft_lstnew(f(cur_old->content))))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur_new = cur_new->next;
		cur_old = cur_old->next;
	}
	return (new);
}
