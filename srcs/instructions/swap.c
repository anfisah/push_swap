/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 11:13:55 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:39 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	swap_a(t_lst **lst, int print)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->element;
	(*lst)->element = (*lst)->next->element;
	(*lst)->next->element = tmp;
	if (print)
		printf("sa\n");
}

void	swap_b(t_lst **lst, int print)
{
	int	tmp;

	if (!*lst || !(*lst)->next)
		return ;
	tmp = (*lst)->element;
	(*lst)->element = (*lst)->next->element;
	(*lst)->next->element = tmp;
	if (print)
		printf("sb\n");
}

void	swap_a_b(t_lst **a, t_lst **b, int print)
{
	swap_a(a, 0);
	swap_b(b, 0);
	if (print)
		printf("ss");
}
