/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:35:47 by bdany             #+#    #+#             */
/*   Updated: 2024/01/23 12:13:22 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_join(char *buffer, char **s)
{
	char	*ref;

	if (buffer[0] == '\0')
	{
		*s = NULL;
		return ;
	}
	ref = ft_strchr(buffer, '\n');
	if (ref)
	{
		*s = ft_strnjoin(*s, buffer, ref - buffer + 1);
		ft_strlcpy(buffer, ref + 1, BUFFER_SIZE);
	}
	else
		*s = ft_strnjoin(*s, buffer, BUFFER_SIZE);
}

char	*get_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	int			bytes;
	char		*s;

	bytes = 1;
	s = NULL;
	ft_join(buffer[fd], &s);
	while (bytes > 0 && !ft_strchr(s, '\n'))
	{
		bytes = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes < BUFFER_SIZE)
			buffer[fd][bytes] = '\0';
		if (bytes > 0)
			ft_join(buffer[fd], &s);
	}
	if (s && s[0] == '\0')
		free(s);
	return (s);
}

char	*get_next_line(int fd)
{
	char	*arr;

	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	arr = get_line(fd);
	return (arr);
}
