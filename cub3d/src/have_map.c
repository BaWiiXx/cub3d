/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 11:49:48 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int size_map (int fd)
{
	char *line;
	int	count_line;

	count_line = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count_line++;
		free(line);
	}
	return (count_line);
}

void get_map(int fd, t_game *data)
{
	char *line;
	int i;

	i = 0;
	data->map.map = malloc(sizeof(char *) * (data->map.line + 1));
	if (!data->map.map)
		return;
	while(i < data->map.line && (line = get_next_line(fd)) != NULL)
	{
		data->map.map[i] = line;
		i++;
	}
	data->map.map[i] = NULL;
}
