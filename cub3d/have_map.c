/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/09/30 14:07:23 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

char **get_map(int fd)
{
	char **map;
	char *line;
	char *tmp;

	map = NULL;
	line = get_next_line(fd);
	if (!line)
		returb(NULL);
	while(tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}