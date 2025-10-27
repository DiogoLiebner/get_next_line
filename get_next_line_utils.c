/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:46:48 by dlima-li          #+#    #+#             */
/*   Updated: 2025/10/27 16:16:11 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*ptr;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	ptr = dest;
	while (*src)
		*ptr++ = *src++;
	*ptr = '\0';
	return (dest);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	char	*fstr;
	size_t	i;
	size_t	istrlen;

	i = 0;
	istrlen = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start >= istrlen)
		return (ft_strdup(""));
	if (len > ft_strlen(str + start))
		len = ft_strlen(str + start);
	fstr = malloc(sizeof(char) * (len + 1));
	if (!fstr)
		return (NULL);
	fstr[0] = '\0';
	while (i < len)
	{
		if (str[start] == '\0')
			break ;
		fstr[i++] = str[start++];
	}
	fstr[i] = '\0';
	return (fstr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*fstr;

	if (!str1 || !str2)
		return (NULL);
	fstr = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!fstr)
		return (NULL);
	fstr[0] = '\0';
	ft_strfill(fstr, str1, str2);
	return (fstr);
}

void	*ft_strfill(char *fstr, char *str1, char *str2)
{
	while (str1)
		*fstr++ = *str1++;
	while (str2)
		*fstr++ = *str2++;
	*fstr = '\0';
}
