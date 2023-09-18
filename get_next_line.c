/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labbamon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:23:16 by labbamon          #+#    #+#             */
/*   Updated: 2023/04/24 16:23:56 by labbamon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*next_line(char *buffer)
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

static	char	*get_line(char *buffer)
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

static	char	*read_line(int fd, char *buffer)
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	buffer = read_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		return (NULL);
	buffer = next_line(buffer);
	if (!buffer)
		return (NULL);
	return (line);
}
/*
int main (void)
 {
 	int fd;
 	char *str;
 	
 	fd = open("pi", O_RDONLY);
 	str = get_next_line(fd);
 	
 	while (str != NULL)
 	{
 		printf("%s", str);
 		free(str);
 		str = get_next_line(fd);
 	}
 }

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		fd;

	fd = open("test baud", O_RDONLY);
	i = 0;
	if (argc == 2)
	{
		while (i < atoi(argv[1])) //&& argc!= NULL)
		{
			line = get_next_line(fd);
			printf("Ligne %d : %s \n", i + 1, line);
			free(line);
			i++;
		}
		return (0);
	}	
	
}*/

/*int main (void)
 {
 	int fd;
 	char *line;
 	int	i;
	
	i = 0;
 	fd = open("test baud", O_RDONLY);
 	line = get_next_line(fd);
 	
 	while (line != NULL)
 	{
 		printf("Ligne %d, %s", i + 1, line);
 		free(line);
 		i++;
 		//str = get_next_line(fd);
 	}
 }*/
