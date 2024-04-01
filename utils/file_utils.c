/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:53 by diahmed           #+#    #+#             */
/*   Updated: 2024/03/12 17:59:35 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flist	*flst_new(char	*name, int mode)
{
	t_flist	*new;

	new = malloc (sizeof(t_flist));
	if (!new)
		return (NULL);
	new -> name = name;
	new->mode = mode;
	new -> next = NULL;
	return (new);
}

t_flist	*flst_last(t_flist *lst)
{
	t_flist	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node -> next)
	{
		node = node -> next;
	}
	return (node);
}

void	flst_addback(t_flist **lst, char *name, int mode)
{
	t_flist	*temp;
	t_flist	*new;

	new = flst_new(name, mode);
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		temp = flst_last(*lst);
		temp -> next = new;
	}
}

void	flst_clear(t_flist **lst)
{
	t_flist	*temp;

	while (*lst)
	{
		temp = (*lst)-> next;
		free((*lst)->name);
		free((*lst));
		*lst = temp;
	}
	*lst = NULL;
}
