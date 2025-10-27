/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlima-li <dlima-li@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:23:52 by dlima-li          #+#    #+#             */
/*   Updated: 2025/10/27 16:16:36 by dlima-li         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *str1, char *str2);
void	*ft_strfill(char *fstr, char *str1, char *str2);
size_t	ft_strlen(char *str);

#endif
