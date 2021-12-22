/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:02:42 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:47 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

char	*read_line(int fd, char *str, int *res)
{
	char	buf[BUFFER_SIZE + 1];

	if (ft_memchr2(str, '\n') == 1)
		return (str);
	while (*res > 0)
	{
		*res = read(fd, buf, BUFFER_SIZE);
		buf[*res] = '\0';
		str = ft_strjoin2(str, buf);
		if ((ft_memchr2(str, '\n') == 1))
			break ;
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int			res;
	int			i;
	static char	*str;

	i = 0;
	res = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL || (read(fd, 0, 0) < 0))
		return (-1);
	if (res == -1)
		return (-1);
	if (str == NULL)
		str = ft_calloc(1, 1);
	str = read_line(fd, str, &res);
	while (str[i] && str[i] != '\n')
		i++;
	(*line) = ft_substr(str, 0, i);
	str = ft_substr2(str, i + 1, (ft_strlen(str) - i) - 1);
	if (*str == 0 && res == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
