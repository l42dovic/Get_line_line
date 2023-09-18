/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labbamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:23:47 by labbamon          #+#    #+#             */
/*   Updated: 2023/03/16 16:24:11 by labbamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*next_line(char *buffer)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	j = ft_strlen((const char *)buffer) - i;
	tmp = ft_substr((const char *)buffer, i, j);
	if (!tmp)
		return (free (buffer), free (tmp), NULL);
	return (free (buffer), tmp);
}

static char	*get_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, j, i);
	if (!line)
		return (free (buffer), free (line), NULL);
	return (line);
}

static char	*read_line(int fd, char *buffer)
{
	ssize_t	buff_txt;
	char	*stash;

	stash = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (!stash)
		return (NULL);
	buff_txt = 1;
	while (buff_txt != 0 && !ft_strchr(buffer, '\n'))
	{
		buff_txt = read(fd, stash, BUFFER_SIZE);
		if (buff_txt == -1)
			return (free(stash), free(buffer), NULL);
		stash[buff_txt] = '\0';
		buffer = ft_strjoin_free(buffer, stash);
		if (buffer[0] == '\0')
			return (free(stash), free(buffer), NULL);
	}
	return (free(stash), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line)
		return (NULL);
	buffer[fd] = next_line(buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	else if (!buffer[fd] && buffer[fd][0] == '\0')
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
/*
int main (void)
 {
 	int fd;
 	int fd1;
 	char *str;
 	char *str1;

 	fd = open("pi", O_RDONLY);
 	fd1 = open("test baud", O_RDONLY);
 	str = get_next_line(fd);
 	str1 = get_next_line(fd1);
 	
 	while (str != NULL || str1 != NULL)
	{
		if (str != NULL)
	    {
	    	printf("%s", str);
 			free(str);
 		}
 		str = get_next_line(fd);
 		if (str1 != NULL)
 		{
 			printf("%s", str1);
 			free(str1);
 		}
 		str1 = get_next_line(fd1);
 	}
 }*/
