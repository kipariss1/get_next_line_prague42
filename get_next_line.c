/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/13 17:19:21 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void renew_stash(char **stash, char *buff) {
    char    *old_stash;

    old_stash = *stash;
    *stash = ft_strjoin(*stash, buff);
    free(old_stash);
}

static int	read_file(int fd, char **stash, char **buff, char **res)
{
	int	read_chars;

	if (!*stash)
		init_buff(stash);
	if (ft_strchr(*stash, '\n'))
	{
		*buff = ft_strdup(*stash);
		init_buff(stash);
		return (1);
	}
	init_buff(buff);
	read_chars = read(fd, *buff, BUFFER_SIZE);
	if (read_chars <= 0 && ft_strlen(*stash) > 0)
	{
		*res = ft_strdup(*stash);
		free_buff(buff);
		free_buff(stash);
		return (0);
	}
	else if (read_chars <= 0 && !ft_strlen(*stash))
	{
		*res = NULL;
		return (0);
	}
	return (1);
}

static void	get_text_before_nl(char **before_nl, char **buff, char **res,
		char **stash)
{
	*before_nl = substr(*buff, 0, ft_strchr(*buff, '\n') + 1 - *buff);
	*res = ft_strjoin(*stash, *before_nl);
	free_buff(before_nl);
	free_buff(stash);
	*stash = substr(*buff, ft_strchr(*buff, '\n') - *buff + 1, ft_strlen(*buff));
	free_buff(buff);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*res;
	char		*before_nl;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	init_buffs(&buff, &res, &before_nl);
	while (read_file(fd, &stash, &buff, &res))
	{
		if (ft_strchr(buff, '\n'))
		{
			get_text_before_nl(&before_nl, &buff, &res, &stash);
			break ;
		}
		else
		{
			renew_stash(&stash, buff);
			free_buff(&buff);
		}
	}
	return (res);
}
