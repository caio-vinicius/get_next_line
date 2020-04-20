/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:47:04 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/20 13:55:14 by caio             ###   ########.fr       */
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

	fd = open("tests/alphabet", O_RDONLY);
	i = 1;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &buffer);
		printf("%dº CHAMADA\n", i);
		printf("%d : |%s|\n", ret, buffer);
		free(buffer);
		i++;
	}
	return (1);
}
