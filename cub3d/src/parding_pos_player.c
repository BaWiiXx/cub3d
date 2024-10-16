/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parding_pos_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:32 by bdany             #+#    #+#             */
/*   Updated: 2024/10/15 15:15:37 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void get_pos_player(t_game *pos)
{
    int x, y;

    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (ft_strchr("NSEW", game->map[y][x]))
            {
                game->player.pos_x = x;
                game->player.pos_y = y;
                game->player.direction = game->map[y][x];
                return;
            }
            x++;
        }
        y++;
    }
    exit_error("Error: No player position found\n");
}
