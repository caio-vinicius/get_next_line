/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:23 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/17 21:16:15 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
    int				ret;
	int				pos;
	char			*aux;
    char			*buffer;
	static char		*tmp;
	//char			*tmp2;
	
	aux = NULL;
	if (!(buffer = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*))))
		return (-1);
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
    while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		//tmp2 = aux;
		aux = ft_strjoin(aux, buffer);
		//(tmp2) ? free(tmp2) : 0;
		if ((ft_strchr_pos(aux, '\n') >= 0))
			break ;
	}
	if (ret < 0)
		return (-1);
	//(tmp2) ? free(tmp2) : 0;
	aux = ft_strjoin(tmp, aux);
	//(tmp) ? free(tmp) : 0;
	pos = ft_strchr_pos(aux, '\n');
	if (pos >= 0)
	{
		*line = ft_substr(aux, 0, pos);
		tmp = ft_substr(aux, pos + 1, ft_strlen(aux));
		free(aux);
		//aux = NULL;
		return (1);
	}
	else
	{
		*line = ft_substr(aux, 0, ft_strlen(aux));
		return (0);
	}
	return (-1);
}
