/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:01 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/01 15:25:54 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

void check_value(int r, int g, int b)
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        printf("error, wrong color value.\n");
        exit(EXIT_FAILURE);
}

uint32_t check_color(int r, int g, int b, int a)
{
    return (r << 16 | g << 8 | b << 8 | a);
}


void flood_file(t_data *data, char **map, int x, int y)
{
    if (y < 0 || y >= game->columns || x < 0 || x >= game->line || map[y][x] != 0)
        return ;
    map[y][x] = '.';
    flood_fill(game, map, x - 1, y);
    flood_fill(game, map, x + 1, y);
    flood_fill(game, map, x, y - 1);
    flood_fill(game, map, x, y + 1);
}