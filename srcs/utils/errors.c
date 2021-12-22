/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:59:08 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/15 10:36:08 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	error(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	error_sign(char *s, int *i)
{
	if ((s[*i] == '-' || s[*i] == '+') && (s[*i + 1] != '0' && s[*i + 1] != '1'
			&& s[*i + 1] != '2' && s[*i + 1] != '3' && s[*i + 1] != '4'
			&& s[*i + 1] != '5' && s[*i + 1] != '6' && s[*i + 1] != '7'
			&& s[*i + 1] != '8' && s[*i + 1] != '9'))
		return (1);
	else
		return (0);
}

void	check_errors(char **av, int *i, int *j)
{
	if (arg(av[*i][*j]) == 1)
		error();
	if ((av[*i][*j] == '-' || av[*i][*j] == '+') && (av[*i][*j + 1] != '0'
			&& av[*i][*j + 1] != '1' && av[*i][*j + 1] != '2'
			&& av[*i][*j + 1] != '3' && av[*i][*j + 1] != '4'
			&& av[*i][*j + 1] != '5' && av[*i][*j + 1] != '6'
			&& av[*i][*j + 1] != '7' && av[*i][*j + 1] != '8'
			&& av[*i][*j + 1] != '9'))
		error();
	if ((av[*i][*j] != '-' && av[*i][*j] != '+' && av[*i][*j] != ' ')
		&& (av[*i][*j + 1] == '-' || av[*i][*j + 1] == '+'))
		error();
}

void	no_args(int ac)
{
	if (ac < 2)
		exit(EXIT_SUCCESS);
}

void	checkdouble(t_lst *a)
{
	t_lst	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->element == a->element)
				error();
			tmp = tmp->next;
		}
		a = a->next;
	}
}
