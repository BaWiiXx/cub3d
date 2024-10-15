/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/15 15:50:17 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

// char **get_map(int fd)
// {
// 	char **map;
// 	char *line;
// 	char *tmp;

// 	map = NULL;
// 	tmp = NULL;
// 	line = get_next_line(fd);
// 	if(!line)
// 		return(NULL);
// 	while(tmp != NULL)
// 	{
// 		line = ft_strjoin(line, tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	map = ft_split(line, '\n');
// 	free(line);
// 	free(tmp);
// 	return (map);
// }

int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

int check_line(char *str, t_game *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_char_valid(str[i]) == 'N' || is_char_valid(str[i]) == 'S'
			|| is_char_valid(str[i]) == 'E' || is_char_valid(str[i]) == 'W')
			data->texture.direction++;
		if(!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

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
