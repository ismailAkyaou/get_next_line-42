/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:53:34 by iakyaou           #+#    #+#             */
/*   Updated: 2022/12/17 22:39:07 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_free(char **save)
{
	if (ft_strlen(*save) == 0)
	{
		free(*save);
		*save = NULL;
	}
}

char	*ft_line(char *str_ing)
{
	int	i;

	if (!str_ing)
		return (NULL);
	i = 0;
	if (ft_strchr(str_ing, '\n'))
	{
		while (str_ing[i] != '\n')
			i++;
		str_ing = ft_substr(str_ing, 0, i + 1);
	}
	return (str_ing);
}

char	*ft_next_line(char *str_ing)
{
	int		i;
	int		j;
	int		len;
	char	*next;

	if (!str_ing)
		return (NULL);
	len = ft_strlen(str_ing);
	if (ft_strchr(str_ing, '\n') && (str_ing[0]))
	{
		i = 0;
		while (str_ing[i] != '\n')
			i++;
		i++;
		next = malloc(len - i + 1);
		j = 0;
		while (i < len)
		{
			next[j++] = str_ing[i++];
		}
		next[j] = '\0';
		return (free(str_ing), str_ing = NULL, next);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*se_buf;
	char		*buf;
	int			read_lin;

	read_lin = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!se_buf)
		se_buf = ft_strdup("");
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read_lin && (!ft_strchr(se_buf, '\n')))
	{
		read_lin = read(fd, buf, BUFFER_SIZE);
		if (read_lin < 0)
			return (free(se_buf), se_buf = NULL, free(buf), NULL);
		buf[read_lin] = '\0';
		se_buf = ft_strjoin(se_buf, buf);
	}
	ft_free(&se_buf);
	line = ft_line(se_buf);
	se_buf = ft_next_line(se_buf);
	return (free(buf), buf = NULL, line);
}
int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY | O_CREAT);
    char *line = get_next_line(fd);
    while(line)
    {
        printf("%s",line);
        line = get_next_line(fd);
    }
}
