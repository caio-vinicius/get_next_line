/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:23 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/20 14:17:43 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	int		ret;
	int		pos;
	char		*aux;
    	char		*buffer;
	static char	*tmp;
	//char		*tmp2;
	
	aux = NULL;
	if (!(buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*))))
		return (-1);
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		aux = ft_strjoin(aux, buffer);
		if ((ft_strchr_pos(aux, '\n') >= 0))
			break ;
	}
	if (ret < 0)
		return (-1);
	aux = ft_strjoin(tmp, aux);
	free(tmp);
	if ((pos = ft_strchr_pos(aux, '\n')) >= 0)
	{
		*line = ft_substr(aux, 0, pos);
		tmp = ft_substr(aux, pos + 1, ft_strlen(aux) - (pos + 1));
		free(aux);
		return (1);
	}
	else
	{
		*line = ft_substr(aux, 0, ft_strlen(aux));
		free(aux);
		return (0);
	}
	return (-1);
}
