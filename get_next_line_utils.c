/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csouza-f <csouza-f@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:46:21 by csouza-f          #+#    #+#             */
/*   Updated: 2020/04/17 15:51:07 by csouza-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
        size_t	i;
        char	*str;

        i = 0;
        if (!s || !(str = malloc(len + 1)))
            return (0);
        while (start + i < len)
        {
            str[i] = s[start + i];
            i++;
        }
        str[i] = '\0';
        return (str);
}

int		ft_strchr_pos(const char *s, int c)
{
		int		i;
		char	*str;

		i = 0;
		str = (char*)s;
		while (str[i])
		{
			if (str[i] == c)
				return (i);
			i++;
		}
		return (-1);
}

size_t		ft_strlen(const char *s)
{
        int i;

        i = 0;
		if (!s || s[i] == '\0')
			return (0);
        while (s[i])
            i++;
        return (i);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
		char		*str;
		int			i;
		int			j;

		i = 0;
		j = 0;
		if ((str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		{
			if (s1)
			{
				while (s1[i])
				{
					str[i] = s1[i];
					i++;
				}
			}
			if (s2)
			{
				while (s2[j])
				{
					str[i] = s2[j];
					i++;
					j++;
				}
			}
			str[i] = '\0';
			return (str);
		}
		return (0);
}

char    *ft_strdup(const char *s1)
{
        char    *str;
        int             i;

        i = 0;
        if (!(str = (char *)malloc(ft_strlen(s1) + 1)))
                return (0);
        while (s1[i])
        {
                str[i] = s1[i];
                i++;
        }
        str[i] = '\0';
        return (str);
}