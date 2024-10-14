/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/14 17:48:49 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}
int check_top_and_bottom(char *line)
{
	int i;

	i = 0;
	while(line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void flood_fill(t_map *data, char **map, int x, int y)
{
    if (y < 0 || y >= data->columns || x < 0 || x >= data->line || map[y][x] != '0')
        return ;
    map[y][x] = '.';
    flood_fill(data, map, x - 1, y);
    flood_fill(data, map, x + 1, y);
    flood_fill(data, map, x, y - 1);
    flood_fill(data, map, x, y + 1);
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

static int check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1 || data->texture.count_no != 1
		|| data->texture.count_ea != 1 || data->texture.count_f != 1 || data->texture.count_c != 1)
	{
		printf("error: texture is not good");
		return (1);
	}
	return (0);
}

static void check_for_texture(t_game *data)
{
	int i;
	char **map_cpy;

	i = 0;
	map_cpy = data->map.map;
	while (map_cpy[i])
	{
		if (ft_strncmp(map_cpy[i], "NO ", 3))
			data->texture.count_no++;
		if (ft_strncmp(map_cpy[i], "SO ", 3))
			data->texture.count_so++;
		if (ft_strncmp(map_cpy[i], "EA ", 3))
			data->texture.count_ea++;
		if (ft_strncmp(map_cpy[i], "WE ", 3))
			data->texture.count_we++;
		if (ft_strncmp(map_cpy[i], "f ", 2))
			data->texture.count_f++;
		if (ft_strncmp(map_cpy[i], "c ", 2))
			data->texture.count_c++;
		i++;
	}
	check_count_texture(data);
}

int load_image(char *line, mlx_texture_t *path)
{
	char *tab;

	tab = ft_split(line, ' ');
	if (!tab || !line)
	{
		free(tab);
		free(line);
		exit(EXIT_FAILURE);
	}
	*path = mlx_load_png(tab[1]);
	free(path);
}

void check_texture(t_game *data)
{
	int i;

	i = 0;
	check_for_texture(data->map.map[i]);
	while (data->map.map[i])
	{
		if (strncmp(data->map.map[i], "NO ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[0]);
		if (strncmp(data->map.map[i], "SO ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[1]);
		if (strncmp(data->map.map[i], "EA ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[2]);
		if (strncmp(data->map.map[i], "WE ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[3]);
		i++;
	}
}

static int	validate_line(char *line, t_game *data)
{
	int	j;

	if (line[0] != '1' && line[0] != ' ')
		return (write(2,"error: invalid map\n", 21));
	j = ft_strlen(line) - 1;
	if (line[j] != '1')
			return (write(2,"error: invalid map\n", 21));
	if (check_line(line, data) == 1 || is_whitespaces(line) == 0)
			return (write(2,"error: invalid map\n", 21));
	if (data->texture.direction > 1 || data->texture.direction < 1)
			return (write(2,"error: invalid map\n", 21));
	return (0);
}

// int check_map(t_game *data)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (data->map.map[i] && !is_whitespaces(data->map.map[i]))
// 		i++;
// 	if (check_top_and_bottom(data->map.map[i]))
// 		return(1);
// 	while (data->map.map[i])
// 	{
// 		flood_fill(data, data->map.map, data->map.line, data->map.columns);
// 		if (validate_line(data->map.map[i], data))
// 			return (1);
// 		i++;
// 	}
// 	i--;
// 	if (check_top_and_bottom(data->map.map[i]))
// 		return(1);
// 	return (0);
// }
