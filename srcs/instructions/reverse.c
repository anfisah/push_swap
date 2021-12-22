/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:23:12 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:33 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	reverse_a(t_lst **lst, int print)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = lstlast(*lst);
	tmp2 = tmp;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	(*lst)->next = tmp2;
	if (print)
		printf("rra\n");
}

void	reverse_b(t_lst **lst, int print)
{
	t_lst	*tmp;
	t_lst	*tmp2;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = lstlast(*lst);
	tmp2 = tmp;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	(*lst)->next = tmp2;
	if (print)
		printf("rrb\n");
}

void	reverse_a_b(t_lst **a, t_lst **b, int print)
{
	reverse_a(a, 0);
	reverse_b(b, 0);
	if (print)
		printf("rrr\n");
}
