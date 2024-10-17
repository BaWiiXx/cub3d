/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:50:29 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/17 18:02:27 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	strlen_flood(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
		|| c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

static void	flood_fill_zero(char **map, int x, int y, t_game *game)
{
	map[y][x] = 'c';
	if (y > 0 && x < strlen_flood(map[y - 1]) && \
	(map[y - 1][x] == '0' || map[y - 1][x] == ' '))
		flood_fill_zero(map, x, y - 1, game);
	else if (!map[y - 1][x] || (y > 0 && x < strlen_flood(map[y - 1]) && \
	map[y - 1][x] != '1' && map[y - 1][x] != 'c'))
	{
		ft_putstr_fd("flood zero\n", 2);
		exit(EXIT_FAILURE);
	}
		// exit_0_non_closed_by_1(map, game);
	if (x > 0 && y < game->map.line && \
	(map[y][x - 1] == '0' || map[y][x - 1] == ' '))
		flood_fill_zero(map, x - 1, y, game);
	else if (!map[y][x - 1] || (x > 0 && y <game->map.line && \
	map[y][x - 1] != '1' && map[y][x - 1] != 'c'))
	{
		ft_putstr_fd("flood zero\n", 2);
		exit(EXIT_FAILURE);
	}
		// exit_0_non_closed_by_1(map, game);
	if (y <game->map.line - 1 && x < strlen_flood(map[y + 1]) && \
	(map[y + 1][x] == '0' || map[y + 1][x] == ' '))
		flood_fill_zero(map, x, y + 1, game);
	else if (!map[y + 1][x] || (y <game->map.line - 1 && \
	x < strlen_flood(map[y + 1]) && map[y + 1][x] != '1' && map[y + 1][x] != 'c'))
	{
		ft_putstr_fd("flood zero\n", 2);
		exit(EXIT_FAILURE);
	}
		// exit_0_non_closed_by_1(map, game);
	if (x < strlen_flood(map[y]) - 1 && y <game->map.line && \
	(map[y][x + 1] == '0' || map[y][x + 1] == ' '))
		flood_fill_zero(map, x + 1, y, game);
	else if (!map[y][x + 1] || (x < strlen_flood(map[y]) - 1 && \
	y <game->map.line && map[y][x + 1] != '1' && map[y][x + 1] != 'c'))
	{
		ft_putstr_fd("flood zero\n", 2);
		exit(EXIT_FAILURE);
	}
	// exit_0_non_closed_by_1(map, game);
}

void	check_zero(t_game *game, char **map_cpy)
{
	int	i;
	int	j;

	j = 0;
	while (map_cpy && map_cpy[j])
	{
		i = 0;
		while (map_cpy[j][i])
		{
			if (map_cpy[j][i] == '0')
			{
				flood_fill_zero(map_cpy, i, j, game);
			}
			i++;
		}
		j++;
	}
	free_tab(map_cpy);
}
