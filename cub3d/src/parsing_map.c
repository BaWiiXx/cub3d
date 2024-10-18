/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/18 17:12:56 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	**cpy_tab(t_game *data)
{
	int	i;
	char **map;

	i = 0;
	map = ft_calloc((data->map.line - data->map.start_map), sizeof(char *));
	while (data->map.map[i])
	{
		map[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	return (map);
}

int	check_line(char *str, t_game *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_char_valid(str[i]) == 'N' || is_char_valid(str[i]) == 'S'
			|| is_char_valid(str[i]) == 'E' || is_char_valid(str[i]) == 'W')
			data->texture.direction++;
		if (!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void while_empty_line(char ***map)
{
	while (*map && **map && ***map == '\n')
		(*map)++;
}

static int	validate_line(char *line, t_game *data)
{
	if (line[0] != '1' && line[0] != ' ')
		exit_error("error: invalid map\n");
	if (check_line(line, data) == 1)
		exit_error("error: invalid map\n");
	if (data->texture.direction != 1)
		exit_error("error: invalid map\n");
	return (0);
}

/*
	map->check teture
		 check color -> c
		 get_only_map() ->  skip les lignes vide
		 					check line de map
							get pos player
							flood_fill_player
							flood_fill_zero
							
		 				   
*/

static int	flood_fill(char **map, int x, int y, t_game *game)
{
	map[y][x] = '1';
	if (y > 0 && map[y - 1][x] == '0')
		flood_fill(map, x, y - 1, game);
	else if (y > 0 && map[y - 1][x] != '1')
		return (1);
	if (x > 0 && map[y][x - 1] == '0')
		flood_fill(map, x - 1, y, game);
	else if (x > 0 && map[y][x - 1] != '1')
		return (1);
	if (y < game->map.line - 1 && map[y + 1][x] == '0')
		flood_fill(map, x, y + 1, game);
	else if (y < game->map.line - 1 && map[y + 1][x] != '1')
		return (1);
	if (x < strlen_flood(map[y]) - 1 && map[y][x + 1] == '0')
		flood_fill(map, x + 1, y, game);
	else if (x < strlen_flood(map[y]) - 1 && map[y][x + 1] != '1')
		return (1);
	return (0);
}

static char	**no_space_arround_player(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = cpy_tab(game);
	x = game->player.x;
	y = game->player.y;
	if (flood_fill(map, x, y, game) == 1)
	{
		ft_putstr_fd("Error: Invalid map\n", 2);
		// free_array(map);
		// free_structs(game);
		exit(EXIT_FAILURE);
	}
	return (map);
}
void is_empty_line(char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		exit_error("error: empty line on map");
}

int	check_map(t_game *data)
{
	int i;

	i = 0;
	char **map_cpy;
	
	while (data->map.map[i])
	{
		is_empty_line(data->map.map[i]);
		validate_line(data->map.map[i], data);
		get_pos_player(data);
		i++;
	}
	map_cpy = no_space_arround_player(data);
	check_zero(data,map_cpy);
	return (0);
}
void parse_map(t_game *data)
{
		while_empty_line(&data->map.map);
		check_map(data);
}