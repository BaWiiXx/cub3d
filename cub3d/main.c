/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/10/01 15:37:25 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// les char valid
int	check_char_is_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

int check_for_texture(t_data *data)
{
	while (data->map)
	{

	}
}

int check_map(t_data *window)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < window->line - 1)
	{
		i = 0;
		while (i < window->columns)
		{
			if (!check_char_map(window->map[j][i]))
			{
				write(2, "Invalid map!\n", 13);
				free_tab(window->map);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
