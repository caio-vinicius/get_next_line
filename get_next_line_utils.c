/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:21 by csouza-f          #+#    #+#             */
/*   Updated: 2020/06/08 17:23:01 by caio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_substr(char *s, unsigned int start, size_t len, int clean)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !(str = malloc(len + 1)))
		return (0);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	if (clean == 1)
		free(s);
	return (str);
}

int		ft_chrp(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char*)s;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	return (-1);
}

size_t	ft_gnl_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((str = malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1)))
	{
		if (s1)
			while (s1[i])
			{
				str[i] = s1[i];
				i++;
			}
		if (s2)
			while (s2[j])
			{
				str[i] = s2[j];
				i++;
				j++;
			}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
