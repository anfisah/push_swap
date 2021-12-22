/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:24:03 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/30 15:29:22 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst_element;

	if (!new || !alst)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		lst_element = ft_lstlast(*alst);
		lst_element->next = new;
	}
}
