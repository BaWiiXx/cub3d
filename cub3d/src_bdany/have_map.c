/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 14:28:20 by bdany            ###   ########.fr       */
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

void	get_map(int fd, t_game *data)
{
	char	*line;
	int		i;

	i = 0;
	data->map.map = malloc(sizeof(char *) * (data->map.line + 1));
	if (!data->map.map)
		return ;
	line = get_next_line(fd);
	while (i < data->map.line && line != NULL)
	{
		data->map.map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	data->map.map[i] = NULL;
}
