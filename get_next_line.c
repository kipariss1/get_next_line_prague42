/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:31:12 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/09 20:23:14 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*nl;
	char		*separated_line;
	size_t		read_bytes;

	if (!buf)
	{
		buf = calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (NULL);
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes <= 0)
			return (free(buf), NULL);
	}
	nl = ft_strchr(buf, '\n');
	if (!nl)
		// TODO: accumulate it to some
		// kind of buffer and read one more chunk of file
		return (NULL);
	separated_line = substr(buf, 0, nl + 1 - buf);
	buf = nl + 1;
	return (separated_line);
}
