/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labbamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:29:20 by labbamon          #+#    #+#             */
/*   Updated: 2023/03/09 16:40:32 by labbamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cs;
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
	start = ft_strlen(s) - start;
	i = 0;
	cs = (char *)s;
	dest = malloc((len * sizeof(char)) + 1);
	if (!dest)
		return (NULL);
	{
		while (i < len && s[i] != '\0')
		{
			dest[i] = cs[i + start];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *) s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
		j = 0;
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest [i + j] = '\0';
	free(s1);
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*ds;
	size_t	i;

	i = 0;
	ds = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!ds)
		return (NULL);
	while (s[i] != '\0')
	{
		ds[i] = s[i];
		i++;
	}
	ds[i] = '\0';
	return (ds);
}
