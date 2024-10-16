/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:49:23 by egomez            #+#    #+#             */
/*   Updated: 2024/08/26 16:49:25 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*void	player_orientation(t_player *player)
{
	if (N || S)
	{
		player->plane_x = 1;
		player->plane_y = 0;
		player->dir_x = 0;
		player->dir_y = -1;
	}
	if (S)
	{
		player->plane_x = -1;
		player->dir_y = 1;
	}
	if (E || W)
	{
		player->plane_x = 0;
		player->plane_y = 1;
		player->dir_x = 1;
		player->dir_y = 0;
	}
	if (W)
	{
		player->plane_y = -1;
		player->dir_x = -1;
	}
}*/

void	init_map(t_game *game)
{
	game->map.map = ft_calloc(1, sizeof(char *) * 8);
	game->map.map[0] = strdup("1111111");
	game->map.map[1] = strdup("1100001");
	game->map.map[2] = strdup("1010101");
	game->map.map[3] = strdup("1000001");
	game->map.map[4] = strdup("1000001");
	game->map.map[5] = strdup("1000001");
	game->map.map[6] = strdup("1111111");
	game->map.map[7] = 0;
	game->map.mlx = mlx_init(S_W, S_H, "Cub3d", 0);
	game->map.img = mlx_new_image(game->map.mlx, S_W, S_H);
	if (!game->map.img)
		return ;
}

void	init_player(t_game *game)
{
	game->player.x = 2.5;
	game->player.y = 4;
	game->player.plane_x = 1;
	game->player.plane_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = -1;
}

void	init_text(t_game *game)
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*e;
	mlx_texture_t	*w;

	n = mlx_load_png("./textures/north.png");
	s = mlx_load_png("./textures/south.png");
	e = mlx_load_png("./textures/east.png");
	w = mlx_load_png("./textures/west.png");
	game->texture.texture[0] = mlx_texture_to_image(game->map.mlx, n);
	game->texture.texture[1] = mlx_texture_to_image(game->map.mlx, s);
	game->texture.texture[2] = mlx_texture_to_image(game->map.mlx, e);
	game->texture.texture[3] = mlx_texture_to_image(game->map.mlx, w);
}
