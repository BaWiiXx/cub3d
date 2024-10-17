/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_pos_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:10:32 by bdany             #+#    #+#             */
/*   Updated: 2024/10/17 13:39:16 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	get_pos_player(t_game *pos)
{
	int	x;
	int	y;

	y = 0;
	while (pos->map.map[y])
	{
		x = 0;
		while (pos->map.map[y][x])
		{
			if (ft_strchr("NSEW", pos->map.map[y][x]))
			{
				pos->player.x = x + 0.5;
				pos->player.y = y + 0.5;
				pos->player.orientation = pos->map.map[y][x];
				return ;
			}
			x++;
		}
		y++;
	}
	exit_error("error: no player position found\n");
}
