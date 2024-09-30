/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:01 by baptiste          #+#    #+#             */
/*   Updated: 2024/09/30 19:42:01 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

uint32_t check_color(int r, int g, int b)
{
}

void flood_file(t_game *game, char **map, int x, int y)
{
    if (y < 0 || y >= game->columns || x < 0 || x >= game->line || map[y][x] != 0)
        return ;
    map[y][x] = '.';
    flood_fill(game, map, x - 1, y);
    flood_fill(game, map, x + 1, y);
    flood_fill(game, map, x, y - 1);
    flood_fill(game, map, x, y + 1);
}