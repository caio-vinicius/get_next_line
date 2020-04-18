/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:47:04 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/17 20:30:08 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd;
	char *buffer;
	int ret;
	int i;

	fd = open("tests/empty_lines", O_RDONLY);
	i = 1;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &buffer);
		printf("%dº CHAMADA\n", i);
		printf("%d : |%s|\n", ret, buffer);
		i++;
	}
	//free(buffer);
	return (1);
}
