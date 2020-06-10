/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:16 by csouza-f          #+#    #+#             */
/*   Updated: 2020/06/08 17:18:43 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_SIZE 10

int	get_next_line(int fd, char **line);
int	ft_chrp(const char *s, int c);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_substr(char *s, unsigned int start, size_t len, int clean);
char	*ft_strchr(const char *s, int c);

#endif
