/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:40:11 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/18 19:12:14 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

static int	check_count_texture(t_game *data)
{
	if (data->texture.count_we != 1 || data->texture.count_so != 1
		|| data->texture.count_no != 1 || data->texture.count_ea != 1
		|| data->texture.count_f != 1 || data->texture.count_c != 1)
		return (1);
	return (0);
}


void	check_for_texture(char **map, t_game *data)
{
	int		i;

	i = 0;
	while(map[i])
	{
		if (!ft_strncmp(map[i], "NO ", 3))
			data->texture.count_no++;
		if (!ft_strncmp(map[i], "SO ", 3))
			data->texture.count_so++;
		if (!ft_strncmp(map[i], "EA ", 3))
			data->texture.count_ea++;
		if (!ft_strncmp(map[i], "WE ", 3))
			data->texture.count_we++;
		if (!ft_strncmp(map[i], "F ", 2))
			data->texture.count_f++;
		if (!ft_strncmp(map[i], "C ", 2))
			data->texture.count_c++;
		i++;
	}
	if(check_count_texture(data) == 1)
	{
		printf("zero texture\n");	
		exit(EXIT_FAILURE);
	}
}

static void	load_image(char *line, mlx_texture_t **path)
{
	char	**tab;
	*path = NULL;
	tab = ft_split(line, ' ');
	
	if (!tab || !line)
	{
		free(tab);
		free(line);
		exit_error("error: texture can't be load1\n");
	}
	printf("tab :%s", tab[1]);	
	*path = mlx_load_png(tab[1]);
	if (!(*path))
	{
		free_tab(tab);
		free(line);
		exit_error("error: texture can't be load\n");
	}
	free(line);
	free_tab(tab);
}

void	check_texture(char **map)
{
	int	i;
	t_game data;

	i = 0;
	while (map[i])
	{
		if (strncmp(map[i], "NO ", 3) == 0)
			load_image(map[i], &data.texture.path[0]);
		else if (strncmp(map[i], "SO ", 3) == 0)
			load_image(map[i], &data.texture.path[1]);
		else if (strncmp(map[i], "EA ", 3) == 0)
			load_image(map[i], &data.texture.path[2]);
		else if (strncmp(map[i], "WE ", 3) == 0)
			load_image(map[i], &data.texture.path[3]);
		else if (strncmp(map[i], "F ", 2) == 0)
			set_color(&data, map[i]);
		else if (strncmp(map[i], "C ", 2) == 0)
		{
			set_color(&data, map[i]);
			break ;
		}
		i++;
	}
	data.map.start_map = i + 1;
}
