/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krassudi <krassudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:59:18 by krassudi          #+#    #+#             */
/*   Updated: 2024/09/13 17:22:20 by krassudi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	res = malloc(1 * sizeof(char));
	while (res)
	{
		free(res);
		res = get_next_line(fd);
        printf("+-----------------------------+ \n");
        printf("%s \n", res);
	}
	(void)ac;
	(void)av;
	return (1);
}
