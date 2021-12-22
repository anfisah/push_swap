/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:18:23 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/20 10:33:54 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

int	arg(char c)
{
	if (c != '0' && c != '1' && c != '2' && c != '3' && c != '4' && c != '5'
		&& c != '6' && c != '7' && c != '8' && c != '9' && c != '-'
		&& c != '+' && c != ' ')
	{
		return (1);
	}
	else
		return (0);
}

void	find_errors(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	no_args(ac);
	error_int(av, ac);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') && av[i][j + 1] == '\0')
				error();
			check_errors(av, &i, &j);
			j++;
		}
		i++;
	}
}

void	error_int(char **av, int ac)
{
	int		i;
	int		j;
	long	nb;

	nb = 0;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i] && av[i][j])
		{
			if ((unsigned long)j < ft_strlen(av[i]) && av[i][j] != ' ')
			{
				nb = ft_atol(&av[i][j]);
			}
			j++;
		}
		i++;
	}
}

long	ft_atol(char *s)
{
	int		i;
	int		neg;
	long	res;

	i = -1;
	neg = 0;
	res = 0;
	while (s[++i] == '+' || s[i] == '-')
		if (s[i] == '-')
			neg = !neg;
	while (s[i] && s[i] != ' ')
		res = (res * 10) + (s[i++] - '0');
	if (res > 2147483647)
		error();
	if (neg)
		return (res);
	res = res * -1;
	if (res < -2147483648)
		error();
	return (res);
}

double	racine(double x)
{
	double	i;

	i = 0.000;
	while (i * i < x)
		i += 0.001;
	return (i);
}
