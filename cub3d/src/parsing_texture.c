/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:40:11 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/17 18:05:26 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

static int	check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1
		|| data->texture.count_no != 1 || data->texture.count_ea != 1
		|| data->texture.count_f != 1 || data->texture.count_c != 1)
	{
		exit_error("error: ");
	}
	return (0);
}

static void	load_image(char *line, mlx_texture_t *path)
{
	char	**tab;

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

void	check_for_texture(t_game *data)
{
	int		i;

	i = 0;
	while (data->map.map[i])
	{
		if (ft_strncmp(data->map.map[i], "NO ", 3))
			data->texture.count_no++;
		else if (ft_strncmp(data->map.map[i], "SO ", 3))
			data->texture.count_so++;
		else if (ft_strncmp(data->map.map[i], "EA ", 3))
			data->texture.count_ea++;
		else if (ft_strncmp(data->map.map[i], "WE ", 3))
			data->texture.count_we++;
		else if (ft_strncmp(data->map.map[i], "F ", 2))
			data->texture.count_f++;
		else if (ft_strncmp(data->map.map[i], "C ", 2))
			data->texture.count_c++;
		i++;
	}
	check_count_texture(data);
}

void	check_texture(t_game *data)
{
	int	i;

	i = 0;
	ft_memset(&data->texture, 0, sizeof(&data->texture));
	while (data->map.map[i])
	{
		if (strncmp(data->map.map[i], "NO ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[0]);
		else if (strncmp(data->map.map[i], "SO ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[1]);
		else if (strncmp(data->map.map[i], "EA ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[2]);
		else if (strncmp(data->map.map[i], "WE ", 3) == 0)
			load_image(data->map.map[i], data->texture.path[3]);
		else if (strncmp(data->map.map[i], "F ", 2) == 0)
			set_color(data, data->map.map[i]);
		else if (strncmp(data->map.map[i], "C ", 2) == 0)
		{
			set_color(data, data->map.map[i]);
			break ;
		}
		i++;
	}
	data->map.start_map = i + 1;
}
