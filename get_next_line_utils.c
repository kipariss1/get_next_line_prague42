/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:09 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/09 22:53:56 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
