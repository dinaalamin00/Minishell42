/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diahmed <diahmed@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:23:02 by diahmed           #+#    #+#             */
/*   Updated: 2023/11/12 16:44:46 by diahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*elem;
	t_list	*head;

	head = 0;
	node = lst;
	while (node)
	{
		elem = malloc (sizeof(t_list));
		if (!elem)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		elem -> content = f(node->content);
		elem -> next = NULL;
		ft_lstadd_back(&head, elem);
		node = node -> next;
	}
	return (head);
}
