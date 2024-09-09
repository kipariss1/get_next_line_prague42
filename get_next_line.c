/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/09 23:29:07 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void init_stash(char **stash){
    if (*stash)
	{
        free(*stash);
	}
    *stash = malloc(sizeof(char) * 1);
    *stash[0] = '\0';
}

static void init_buff(char **buff) {
    *buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!*buff)
        return ;
    ft_memset(*buff, '\0', BUFFER_SIZE + 1);
}

static int  read_file(int fd, char **stash, char **buff, char **res) {
    int			read_chars;

    if (!*stash)
        init_stash(stash);
    if (ft_strchr(*stash, '\n')){
        *buff = ft_strdup(*stash);
        init_stash(stash);
        return (1);
    }
    init_buff(buff);
    read_chars = read(fd, *buff, BUFFER_SIZE);
    if (read_chars <= 0) {
        *res = ft_strdup(*stash);
        return (free(*buff), free(*stash), 0);
    }
    return (1);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*res;
	char		*before_nl;
	static char	*stash;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read_file(fd, &stash, &buff, &res))
	{
		if (ft_strchr(buff, '\n'))
		{
			before_nl = substr(buff, 0, ft_strchr(buff, '\n') + 1 - buff);
			res = ft_strjoin(stash, before_nl);
            free(before_nl);
			free(stash);
			stash = substr(buff, ft_strchr(buff, '\n') - buff + 1,
					ft_strlen(buff));
			free(buff);
            break;
		}
		else
		{
			stash = ft_strjoin(stash, buff);
			free(buff);
		}
	}
	return (res);
}
