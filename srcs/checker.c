/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:08:39 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/15 15:28:19 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	inst_swap_push(char *line, t_lst **a, t_lst **b)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_a(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		swap_b(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		swap_a_b(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(b, a, 0);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(a, b, 0);
	else
		inst_rot_rev(line, a, b);
}

void	inst_rot_rev(char *line, t_lst **a, t_lst **b)
{
	if (ft_strcmp(line, "ra") == 0)
		rotate_a(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_b(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_a_b(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		reverse_a(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		reverse_b(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		reverse_a_b(a, b, 0);
	else if (ft_strcmp(line, "\0") != 0)
		error();
	else
		return ;
}

void	instructions(t_lst **a, t_lst **b)
{
	int		gnl;
	char	*line;
	int		nb_inst;

	line = NULL;
	gnl = 1;
	nb_inst = 0;
	while (gnl != 0)
	{
		gnl = get_next_line(0, &line);
		inst_swap_push(line, a, b);
		free(line);
		nb_inst++;
	}
}

void	display_ok_ko(t_lst *a)
{
	t_lst	*b;

	b = NULL;
	checkdouble(a);
	instructions(&a, &b);
	if (lstsize(a) == 0)
		exit(EXIT_SUCCESS);
	if (lstsize(b) != 0)
	{
		write(1, "\033[0;31mKO\033[0m\n", 14);
		lstclear(&b);
		lstclear(&a);
		exit(EXIT_SUCCESS);
	}
	if (!is_sort(a))
	{
		write(1, "\033[0;31mKO\033[0m\n", 14);
		lstclear(&a);
		exit(EXIT_SUCCESS);
	}
	write(1, "\033[0;32mOK\033[0m\n", 14);
	lstclear(&a);
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
	display_ok_ko(a);
}
