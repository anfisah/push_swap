/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:55:54 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:55 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	find_pos(t_lst *lst, int element)
{
	int	pos;

	pos = 0;
	while (lst && lst->element != element)
	{
		lst = lst->next;
		pos++;
	}
	return (pos);
}

int	is_max(t_lst *lst)
{
	int	max;

	max = -2147483648;
	while (lst)
	{
		if (lst->element > max)
			max = lst->element;
		lst = lst->next;
	}
	return (max);
}

int	is_min(t_lst *lst)
{
	int	min;

	min = 2147483647;
	while (lst)
	{
		if (lst->element < min)
			min = lst->element;
		lst = lst->next;
	}
	return (min);
}

int	is_sort(t_lst *lst)
{
	while (lst->next != NULL)
	{
		if (lst->element > lst->next->element)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	put_nb_top(t_lst **a, t_lst **b, int pos, int size)
{
	if (pos < size / 2)
	{
		while (pos > 0)
		{
			rotate_a(a, 1);
			pos--;
		}
	}
	else
	{
		while (pos != size)
		{
			reverse_a(a, 1);
			pos++;
		}
	}
	push_b(a, b, 1);
}
