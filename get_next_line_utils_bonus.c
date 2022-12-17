/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:59:01 by iakyaou           #+#    #+#             */
/*   Updated: 2022/12/17 21:57:43 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *str)
{
	char	*allocation;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	i = 0;
	allocation = (char *)malloc((str_len + 1) * sizeof(char));
	if (!allocation)
		return (0);
	return (ft_memcpy(allocation, str, str_len + 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*alocation;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	alocation = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!alocation)
		return (NULL);
	while (s1[i])
	{
		alocation[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		alocation[i] = s2[j];
		i++;
		j++;
	}
	alocation[i] = '\0';
	free(s1);
	return (alocation);
}

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start >= (ft_strlen(s)))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
