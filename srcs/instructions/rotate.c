/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:52:09 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:36 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	rotate_a(t_lst **lst, int print)
{
	t_lst	*tmp;
	t_lst	*last;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = tmp;
	tmp->next = NULL;
	if (print)
		printf("ra\n");
}

void	rotate_b(t_lst **lst, int print)
{
	t_lst	*tmp;
	t_lst	*last;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	last = ft_lstlast(*lst);
	last->next = tmp;
	tmp->next = NULL;
	if (print)
		printf("rb\n");
}

void	rotate_a_b(t_lst **a, t_lst **b, int print)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	if (print)
		printf("rr\n");
}
