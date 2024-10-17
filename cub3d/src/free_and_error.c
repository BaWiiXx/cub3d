/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:31:23 by bdany             #+#    #+#             */
/*   Updated: 2024/10/17 18:29:51 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

// void	free_all(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	if (game->map.img)
// 		mlx_delete_image(game->map.mlx, game->map.img);
// 	if (game->map.mlx)
// 		mlx_close_window(game->map.mlx);
// 	if (game->map.map)
// 	{
// 		while (game->map.map[i])
// 		{
// 			free(game->map.map[i]);
// 			i++;
// 		}
// 		free(game->map.map);
// 	}
// }

void	exit_error(char *str)
{
	// t_game *game;
	
	ft_putstr_fd(str, 2);
	// free_tab(game);
	// free_all(game);
	exit(EXIT_FAILURE);
}


