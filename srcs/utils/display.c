/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:06:57 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:42 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

void	display(t_lst *a, t_lst *b)
{
	ft_putstr_fd("-------------------\n", 0);
	while (a || b)
	{
		if (a)
		{
			printf("%d\t  ", a->element);
			a = a->next;
		}
		else
			printf(" \t  ");
		if (b)
		{
			printf("%d\n", b->element);
			b = b->next;
		}
		else
			printf(" \n");
	}
	printf("-\t  -\n");
	printf("a\t  b\n");
}
