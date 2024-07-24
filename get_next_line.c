/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/07/24 18:26:23 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buf;
    size_t  read_bytes;
    
    buf = calloc(BUFFER_SIZE + 1, sizeof(char));
    if (!buf)
        return (NULL);
    read_bytes = read(fd, buf, BUFFER_SIZE);
    if (read_bytes <= 0)
        return (free(buf), NULL);
    // TODO: make management of the buffer and cut it by newlines
    return (buf);
}
