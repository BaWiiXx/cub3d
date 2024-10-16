/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:50:29 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 11:55:01 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

static int check_if_space(char **map, int x, int y)
{
    return (map[y - 1][x] == '1' && map[y + 1][x] == '1' &&
            map[y][x - 1] == '1' && map[y][x + 1] == '1');
}
