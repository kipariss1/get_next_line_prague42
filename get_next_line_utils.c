/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:49:15 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/13 17:06:06 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	init_buff(char **buff)
{
	size_t	buff_size;

	if (*buff)
		free(*buff);
	buff_size = BUFFER_SIZE + 1;
	*buff = malloc(sizeof(char) * buff_size);
	if (!*buff)
		return ;
	ft_memset(*buff, '\0', buff_size);
}

void	init_buffs(char **buff, char **res, char **before_nl)
{
	*buff = NULL;
	*res = NULL;
	*before_nl = NULL;
}

void	free_buff(char **buff)
{
	if (*buff)
		free(*buff);
	*buff = NULL;
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (0);
}

char	*substr(char *s, ssize_t begin, ssize_t offset)
{
	char	*res;
	int		i;

	res = calloc(begin + offset + 1, sizeof(char));
	i = 0;
	while (s && s[begin + i] && i < offset)
	{
		res[i] = s[begin + i];
		i++;
	}
	if (!i)
		return (free(res), NULL);
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (res == 0)
		return (0);
	while (*s1)
	{
		res[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		res[i] = *s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*ptr;

	ptr = s;
	if (n < 0)
		return (s);
	while (n-- > 0)
	{
		*ptr++ = c;
	}
	return (s);
}

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;
	size_t	n;

	n = ft_strlen((char *)s);
	res = malloc(n + 1);
	if (!res)
		return (0);
	ft_memset(res, '\0', n + 1);
	i = 0;
	while (s[i] && i < n)
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
