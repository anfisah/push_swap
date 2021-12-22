/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:02:06 by ccoto             #+#    #+#             */
/*   Updated: 2021/04/12 14:55:44 by ccoto            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"

char	*join(char *s1, char *s2, char *s3)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		s3[i] = s2[j];
		j++;
		i++;
	}
	s3[i] = 0;
	return (s3);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	s3 = join(s1, s2, s3);
	if (s1)
		free((char *)s1);
	return (s3);
}

int	ft_memchr2(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	index;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	index = 0;
	while (index < len && ((index + start) < size))
	{
		str[index] = s[start + index];
		index++;
	}
	str[index] = '\0';
	free((char *)s);
	return (str);
}
