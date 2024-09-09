/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/09 21:52:35 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char        *buff;
    int         read_chars;
    char        *res;
    char        *before_nl;
    static char *stash;    

    stash = malloc(sizeof(char) * 1);
    stash[0] = '\0';
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while (1) {
        buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff)
            return (NULL);
        ft_memset(buff, '\0', BUFFER_SIZE + 1);
        read_chars = read(fd, buff, BUFFER_SIZE);
        if (read_chars <= 0)
            break;
        if (ft_strchr(buff, '\n')) {
            before_nl = substr(buff, 0, ft_strchr(buff, '\n') + 1 - buff);
            res = ft_strjoin(stash, before_nl);
            free(stash);
            stash = substr(buff, ft_strchr(buff, '\n') - buff + 1, ft_strlen(buff));
            free(buff);
            break;
        }
        else {
            stash = ft_strjoin(stash, buff);
            free(buff);
        }
    }
    return (res);
}
