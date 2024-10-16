/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/16 11:51:59 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

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

static int check_arround_0(char **map, int x, int y)
{
    if (map[y - 1][x] != '1' && map[y - 1][x] != '0')
        if (map[y - 1][x] != ' ' || !check_space(map, x, y - 1))
            return (0);
    if (map[y + 1][x] != '1' && map[y + 1][x] != '0')
        if (map[y + 1][x] != ' ' || !check_space(map, x, y + 1))
            return (0);
    if (map[y][x - 1] != '1' && map[y][x - 1] != '0')
        if (map[y][x - 1] != ' ' || !check_space(map, x - 1, y))
            return (0);
    if (map[y][x + 1] != '1' && map[y][x + 1] != '0')
        if (map[y][x + 1] != ' ' || !check_space(map, x + 1, y))
            return (0);
    return (1);
}

void load_image(char *line, mlx_texture_t *path)
{
	char *tab;

	tab = ft_split(line, ' ');
	if (!tab || !line)
	{
		free(tab);
		free(line);
		exit_error("error");
	}
	path = mlx_load_png(tab[1]);
	if (!path)
	{
		free(tab);
		free(line);
		exit_error("error");
	}
	free(tab);
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

int check_map(t_game *data)
{
	unsigned int	i;

	i = 0;
	while (data->map.map[i] && !is_whitespaces(data->map.map[i]))
		i++;
	if (check_top_and_bottom(data->map.map[i]))
		return(1);
	while (data->map.map[i])
	{
		check_arround_0(data->map.map, i, i);
		if (validate_line(data->map.map[i], data))
			return (1);
		i++;
	}
	i--;
	if (check_top_and_bottom(data->map.map[i]))
		return(1);
	return (0);
}
