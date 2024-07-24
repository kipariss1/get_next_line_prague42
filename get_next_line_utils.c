/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:09 by krassudi          #+#    #+#             */
/*   Updated: 2024/07/24 20:54:50 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strchr(const char *s, int c)
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


char    *substr(char *s, ssize_t begin, ssize_t offset)
{
    char    *res;
    int     i;

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