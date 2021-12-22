/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 03:06:10 by ccoto             #+#    #+#             */
/*   Updated: 2021/03/30 11:42:32 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*sup;

	if (!*lst)
		return ;
	while (*lst)
	{
		sup = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = sup;
	}
}
