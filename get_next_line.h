/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iakyaou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:48:01 by iakyaou           #+#    #+#             */
/*   Updated: 2022/12/17 18:59:17 by iakyaou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

char	*ft_line(char *str_ing);
char	*ft_next_line(char *str_ing);
char	*get_next_line(int fd);

int		ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif