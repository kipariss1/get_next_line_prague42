/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/13 16:39:50 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void init_buff(char **buff, char type){
    size_t buff_size;

    if (*buff)
        free(*buff);
    buff_size = (type == 'b') ? BUFFER_SIZE + 1 : 1;
    *buff = malloc(sizeof(char) * buff_size);
    if (!*buff)
        return ;
    ft_memset(*buff, '\0', buff_size);
}

static void init_buffs(char **buff, char **res, char **before_nl){
    *buff = NULL;
    *res = NULL;
    *before_nl = NULL;
}

static void free_buff(char **buff){
    if (*buff)
        free(*buff);
    *buff = NULL;
}

static int  read_file(int fd, char **stash, char **buff, char **res) {
    int			read_chars;

    if (!*stash)
        init_buff(stash, 's');
    if (ft_strchr(*stash, '\n')){
        *buff = ft_strdup(*stash);
        init_buff(stash, 's');
        return (1);
    }
    init_buff(buff, 'b');
    read_chars = read(fd, *buff, BUFFER_SIZE);
    if (read_chars <= 0  && ft_strlen(*stash) > 0) {
        *res = ft_strdup(*stash);
        free_buff(buff);
        free_buff(stash);
        return (0);
    }
    else if (read_chars <= 0  && !ft_strlen(*stash)) {
        *res = NULL;
        return (0);
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
    init_buffs(&buff, &res, &before_nl);
	while (read_file(fd, &stash, &buff, &res))
	{
		if (ft_strchr(buff, '\n'))
		{
			before_nl = substr(buff, 0, ft_strchr(buff, '\n') + 1 - buff);
			res = ft_strjoin(stash, before_nl);
            free_buff(&before_nl);
			free_buff(&stash);
			stash = substr(buff, ft_strchr(buff, '\n') - buff + 1,
					ft_strlen(buff));
			free_buff(&buff);
            break;
		}
		else
		{
			stash = ft_strjoin(stash, buff);
			free_buff(&buff);
		}
	}
	return (res);
}
