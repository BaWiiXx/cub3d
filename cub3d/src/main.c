/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/10/17 17:13:44 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	main(int argc, char **argv)
{
	t_game	*data;
	char **all_map;

	data = NULL;
	if (argc != 2)
		return(write(2, "error: wrong size of argument\n", 31));
	check_cub_argv(argv[1]);
	data->fd = open_fd(data, argv);
	size_map(data->fd);
	close(data->fd);
	open_fd(data, argv);
	all_map = get_map(data);
	check_for_texture(data);
	check_texture(data);
	data->map.map = &all_map[data->map.start_map];
	parse_map(data);
}
