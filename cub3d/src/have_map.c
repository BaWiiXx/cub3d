/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/17 17:55:57 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	size_map(int fd)
{
	char	*line;
	int		count_line;

	count_line = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count_line++;
	}
	free(line);
	return (count_line);
}

char	**get_map(t_game *data)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (data->map.line + 1));
	if (!map)
		exit_error("error: empty map\n");
	line = get_next_line(data->fd);
	while (i < data->map.line && line != NULL)
	{
		map[i] = line;
		free(line);
		line = get_next_line(data->fd);
		i++;
	}
	free(line);
	map[i] = NULL;
	return(map);
}
