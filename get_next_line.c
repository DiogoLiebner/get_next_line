/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:09:04 by dlima-li          #+#    #+#             */
/*   Updated: 2025/10/29 15:27:14 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (*(ptr + i))
	{
		if (s[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if ((char)c == '\0')
		return (ptr + i);
	return (0);
}

static char	*fill_line_buffer(int fd, char *remchar, char *buffer)
{
	char	*temp;
	int		rvalue;

	rvalue = 1;
	while (rvalue > 0 && (!remchar || !ft_strchr(remchar, '\n')))
	{
		rvalue = read(fd, buffer, BUFFER_SIZE);
		if (rvalue < 0)
		{
			free(remchar);
			return (NULL);
		}
		if (rvalue == 0)
			break ;
		buffer[rvalue] = '\0';
		if (!remchar)
			remchar = ft_strdup("");
		temp = remchar;
		remchar = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (remchar);
}

static char	*set_line(char *linebuffer)
{
	char	*remchar;
	size_t	i;

	i = 0;
	while (linebuffer[i] != '\n' && linebuffer[i] != '\0')
		i++;
	if (linebuffer[i] == '\0')
		return (NULL);
	remchar = ft_substr(linebuffer, i + 1, ft_strlen(linebuffer) - i);
	if (*remchar == '\0')
	{
		free(remchar);
		remchar = NULL;
	}
	linebuffer[i + 1] = '\0';
	return (remchar);
}

char	*get_next_line(int fd)
{
	static char	*remchar;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(remchar);
		remchar = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	line = fill_line_buffer(fd, remchar, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(remchar);
		remchar = NULL;
		return (NULL);
	}
	remchar = set_line(line);
	return (line);
}
