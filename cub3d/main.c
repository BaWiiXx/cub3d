/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/09/30 19:42:13 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// les char valid
int	check_char_is_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

// check tout les char
int	check_char(t_game *window, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	j = 0;
	count = 0;
	while (j < window->line - 1)
	{
		i = 0;
		while (i < window->columns)
		{
			if (!check_char_is_valid(window->map[j][i]))
			{
				write(2, "Invalid map!\n", 13);
				free_tab(window->map);
				exit(0);
			}
			if (window->map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}
