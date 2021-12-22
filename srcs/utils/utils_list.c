/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:59:03 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/14 10:13:10 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

t_lst	*lstnew(int element)
{
	t_lst	*tmp;

	tmp = malloc(sizeof(t_lst));
	if (!tmp)
		error();
	tmp->element = element;
	tmp->next = NULL;
	return (tmp);
}

t_lst	*lstlast(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_lst **alst, t_lst *new)
{
	t_lst	*lst_element;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		lst_element = lstlast(*alst);
		lst_element->next = new;
	}
}

int	lstsize(t_lst *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	lstclear(t_lst **lst)
{
	t_lst	*sup;

	if (!*lst)
		return ;
	while (*lst)
	{
		sup = (*lst)->next;
		free(*lst);
		*lst = sup;
	}
}
