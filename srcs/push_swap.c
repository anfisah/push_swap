/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:08:42 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/15 15:28:14 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	micro_sort(t_lst **a)
{
	if ((*a)->element > lstlast(*a)->element
		&& (*a)->element > (*a)->next->element)
		rotate_a(a, 1);
	if ((*a)->next->element > lstlast(*a)->element)
		reverse_a(a, 1);
	if ((*a)->element > (*a)->next->element)
		swap_a(a, 1);
	lstclear(a);
}

void	mini_sort(t_lst **a, t_lst **b)
{
	if (is_sort(*a))
		return ;
	if (lstlast(*a)->element == is_min(*a))
		reverse_a(a, 1);
	if ((*a)->element == is_min(*a))
		push_b(a, b, 1);
	while ((*a)->element != is_min(*a))
		rotate_a(a, 1);
	push_b(a, b, 1);
	if (lstsize(*b) < 2)
	{
		while ((*a)->element != is_min(*a))
			rotate_a(a, 1);
		push_b(a, b, 1);
	}
	micro_sort(a);
	push_a(b, a, 1);
	push_a(b, a, 1);
	lstclear(a);
}

void	high_sort(t_lst **a, t_lst **b)
{
	int	*tab;

	tab = tab_for_range(*a, lstsize(*a));
	tab = ft_sort_int_tab(tab, lstsize(*a));
	if (is_sort(*a))
		return ;
	push_to_b(a, b, tab, lstsize(*a));
	while (*b)
		push_to_a(a, b);
	free(tab);
	lstclear(a);
}

void	push_swap(t_lst *a)
{
	t_lst	*b;

	b = NULL;
	checkdouble(a);
	if (is_sort(a))
		lstclear(&a);
	if (lstsize(a) > 1 && lstsize(a) <= 3)
		micro_sort(&a);
	else if (lstsize(a) > 3 && lstsize(a) <= 5)
		mini_sort(&a, &b);
	else if (lstsize(a) > 5)
		high_sort(&a, &b);
	else
		exit(EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_lst	*a;
	t_lst	*elem;

	a = NULL;
	elem = NULL;
	find_errors(av, ac);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i] && av[i][j])
		{
			if ((unsigned long)j < ft_strlen(av[i]) && av[i][j] != ' ')
			{
				elem = lstnew(ft_atoi(&av[i][j]));
				lstadd_back(&a, elem);
				j = j + size_int(elem->element);
			}
			j++;
		}
		i++;
	}
	push_swap(a);
}
