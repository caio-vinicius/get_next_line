/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:23 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/21 15:19:39 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cat_clean(char *str1, char *str2, int ret, int clean)
{
	char	*tmp;
	char	*tmp2;
	char	*aux;

	if (ret != 0)
		str2[ret] = '\0';
	if (clean == 0)
		tmp = str1;
	else if (clean == 1)
		tmp = str2;
	else if (clean == 2)
	{
		tmp = str1;
		tmp2 = str2;
	}
	aux = ft_strjoin(str1, str2);
	free(tmp);
	if (clean == 2)
		free(tmp2);
	return (aux);
}

int	get_next_line(int fd, char **line)
{
	int		ret;
	int		pos;
	char		*aux;
	char		buf[BUFFER_SIZE + 1];
	static char	*tmp;

	aux = NULL;
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	while (ft_chrp(aux, '\n') < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
		aux = ft_cat_clean(aux, buf, ret, 0);
	if (ret < 0)
		return (-1);
	aux = ft_cat_clean(tmp, aux, 0, 2);
	if ((pos = ft_chrp(aux, '\n')) >= 0)
	{
		*line = ft_substr(aux, 0, pos, 0);
		tmp = ft_substr(aux, pos + 1, ft_strlen(aux) - (pos + 1), 1);
		return (1);
	}
	else
	{
		*line = ft_substr(aux, 0, ft_strlen(aux), 1);
		return (0);
	}
}
