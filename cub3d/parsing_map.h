/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/02 15:52:21 by bdany            ###   ########.fr       */
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

void flood_fill(t_data *data, char **map, int x, int y)
{
    if (y < 0 || y >= data->columns || x < 0 || x >= data->line || map[y][x] != 0)
        return ;
    map[y][x] = '.';
    flood_fill(data, map, x - 1, y);
    flood_fill(data, map, x + 1, y);
    flood_fill(data, map, x, y - 1);
    flood_fill(data, map, x, y + 1);
}

int is_whitespaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '9' && str[i] <= '13' || str[i] == '32')
			i++;
		else
			return (1);
	}
	return (0);
}

int check_line(char *str, t_data *data)
{
	int i;

	while (str[i])
	{
		if (is_char_valid(str[i]) == 'N' || is_char_valid(str[i]) == 'S'
			|| is_char_valid(str[i]) == 'E' || is_char_valid(str[i]) == 'W');
			data->texture->direction++;
		if(!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_count_texture(t_data *data)
{
	if (data->texture->count_we != 1 || data->texture->count_so != 1 || data->texture->count_no != 1
		|| data->texture->count_ea != 1 || data->texture->count_f != 1 || data->texture->count_c != 1)
	{
		printf("error: texture is not good");
		return (1);
	}
	return (0);
}

int check_for_texture(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "NO ", 3))
			data->texture->count_no++;
		if (ft_strncmp(data->map[i], "SO ", 3))
			data->texture->count_so++;
		if (ft_strncmp(data->map[i], "EA ", 3))
			data->texture->count_ea++;
		if (ft_strncmp(data->map[i], "WE ", 3))
			data->texture->count_we++;
		if (ft_strncmp(data->map[i], "f ", 2))
			data->texture->count_f++;
		if (ft_strncmp(data->map[i], "c ", 2))
			data->texture->count_c++;
		i++;
	}
	if (check_count_texture(data));
		exit(EXIT_FAILURE);
	return (0);
}

static int	validate_line(char *line, t_data *data)
{
	int	j;

	if (line[0] != '1' && line[0] != ' ')
		return (write(2,"error: invalid map\n", 21));
	j = ft_strlen(line) - 1;
	if (line[j] != '1')
			return (write(2,"error: invalid map\n", 21));
	if (check_line(line, data) == 1 || is_whitespaces(line) == 0)
			return (write(2,"error: invalid map\n", 21));
	if (data->texture->direction > 1)
			return (write(2,"error: invalid map\n", 21));
	return (0);
}

int check_map(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (data->map[i] && !is_whitespaces(data->map[i]))
		i++;
	if (check_top_and_bottom(data->map[i]))
		printf("error: map not closed\n");
	while (data->map[i])
	{
		flood_fill(data, data->map, data->line, data->columns);
		if (check_line(data->map[i], data))
			return (1);
		i++;
	}
	i--;
	if (check_top_and_bottom(data->map[i]))
		printf("error: map not closed\n");
	return (0);
}