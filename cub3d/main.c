/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/09/23 14:11:55 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// .cub
void	check_argv(char *argv)
{
	int	size_argv;

	size_argv = ft_strlen(argv);
	if ((size_argv >= 4) && (ft_strcmp(argv + size_argv - 4, ".cub") == 0))
		return ;
	write(2, "Error:\nThe map should end with .ber\n", 36);
	exit(0);
}

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
			if (!check_char_is_valid(window->tab[j][i]))
			{
				write(2, "Invalid map!\n", 13);
				free_tab(window->tab);
				exit(0);
			}
			if (window->tab[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}
// check les couleur
uint32_t check_color(int r, int g, int b, int a)
{
    
}