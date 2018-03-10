/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:36:21 by atikhono          #+#    #+#             */
/*   Updated: 2018/02/21 17:36:11 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *content, size_t content_size)
{
	free(content);
	content_size -= content_size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*cur;
	t_list	*new;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	cur = f(lst);
	new = ft_lstnew(cur->content, cur->content_size);
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst != NULL)
	{
		cur = f(lst);
		new->next = ft_lstnew(cur->content, cur->content_size);
		if (!new->next)
		{
			ft_lstdel(&start, &del);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
