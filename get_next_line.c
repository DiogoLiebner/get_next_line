/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:09:04 by dlima-li          #+#    #+#             */
/*   Updated: 2025/10/27 16:18:38 by dlima-li         ###   ########.fr       */
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

char	*fill_line_buffer(int fd, char *left_c, char *buffer)
{
	char	*temp;

	read(fd, )
}

char	*set_line(char *line_buffer)
{
	
}

char	*get_next_line(int fd)
{
}
