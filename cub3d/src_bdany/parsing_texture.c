/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:40:11 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 16:18:40 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

static int	check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1
		|| data->texture.count_no != 1 || data->texture.count_ea != 1
		|| data->texture.count_f != 1 || data->texture.count_c != 1)
	{
		printf("error: ");
		return (1);
	}
	return (0);
}

void	load_image(char *line, mlx_texture_t *path)
{
	char	*tab;

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

static void	check_for_texture(t_game *data)
{
	int		i;
	char	**map_cpy;

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
		if (ft_strncmp(map_cpy[i], "F ", 2))
			data->texture.count_f++;
		if (ft_strncmp(map_cpy[i], "C ", 2))
			data->texture.count_c++;
		i++;
	}
	check_count_texture(data);
}

void	check_texture(t_game *data)
{
	int	i;

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
		if (strncmp(data->map.map[i], "F ", 2) == 0)
			set_color(data->ceilfloor.floor_color, data->map.map[i]);
		if (strncmp(data->map.map[i], "C ", 2) == 0)
			set_color(data->ceilfloor.ceil_color, data->map.map[i]);
		i++;
	}
}
