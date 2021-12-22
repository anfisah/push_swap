/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:03:50 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 16:19:15 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	push_a(t_lst **a, t_lst **b, int print)
{
	t_lst	*a_1;

	if (!*a)
		return ;
	a_1 = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = a_1;
	if (print)
		printf("pa\n");
}

void	push_b(t_lst **a, t_lst **b, int print)
{
	t_lst	*a_1;

	if (!*a)
		return ;
	a_1 = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = a_1;
	if (print)
		printf("pb\n");
}
