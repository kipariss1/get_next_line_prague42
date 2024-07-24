/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:09 by krassudi          #+#    #+#             */
/*   Updated: 2024/07/24 14:26:41 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t read_file_until_new_line(int fd)
{
    size_t  read_bytes;
    char    buf;

    read_bytes = 0;
    while (read(fd, &buf, 1) > 0 && buf != '\n')
        read_bytes++;
    return (read_bytes);
}