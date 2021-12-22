/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:55:54 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/14 12:48:08 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	*tab_for_range(t_lst *lst, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	if (!tab)
		error();
	while (lst)
	{
		tab[i] = lst->element;
		lst = lst->next;
		i++;
	}
	return (tab);
}

void	push_by_range(t_lst **a, t_lst **b,
							int range_min, int range_max)
{
	int		pos;
	int		size;
	t_lst	*tmp;

	tmp = *a;
	size = lstsize(*a);
	pos = 0;
	while (tmp)
	{
		if (tmp->element >= range_min && tmp->element <= range_max)
		{
			put_nb_top(a, b, pos, size);
			tmp = *a;
			pos = -1;
		}
		else
			tmp = tmp->next;
		pos++;
	}
}

void	push_to_a(t_lst **a, t_lst **b)
{
	if (find_pos(*b, is_max(*b)) <= lstsize(*b) / 2)
		while (find_pos(*b, is_max(*b)) != 0)
			rotate_b(b, 1);
	else
		while (find_pos(*b, is_max(*b)) != 0)
			reverse_b(b, 1);
	push_a(b, a, 1);
}

void	push_to_b(t_lst **a, t_lst **b, int *tab, int size)
{
	int	number_range;
	int	range_min;
	int	range_max;
	int	i;

	i = 0;
	range_max = 0;
	range_min = 0;
	number_range = racine(size) / 1.5;
	while (i != number_range)
	{
		if (i != 0)
			range_min = size / number_range * i;
		if (i == number_range - 1)
			range_max = size - 1;
		else
			range_max = size / number_range * (i + 1);
		push_by_range(a, b, tab[range_min], tab[range_max]);
		i++;
	}
}
