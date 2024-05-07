/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafaisal <mafaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 13:46:53 by diahmed           #+#    #+#             */
/*   Updated: 2024/05/05 15:05:30 by mafaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_flist	*flst_new(char	*name, int mode)
{
	t_flist	*new;

	new = ft_calloc(sizeof(t_flist), 1);
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

bool	flst_addback(t_flist **lst, char *name, int mode)
{
	t_flist	*temp;
	t_flist	*new;

	new = flst_new(name, mode);
	if (!new)
		return (free(name), FAILURE);
	if (!*lst)
		*lst = new;
	else
	{
		temp = flst_last(*lst);
		temp -> next = new;
	}
	return (SUCCESS);
}
