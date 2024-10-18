/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/10/18 18:12:41 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	main(int argc, char **argv)
{
	t_game	data;
	char **all_map;

	if (argc != 2)
		return(write(2, "error: wrong size of argument\n", 31));
	check_cub_argv(argv[1]);
	init_all_of_value(&data);
	open_fd(&data, argv);
	size_map(&data);
	close(data.fd);
	open_fd(&data, argv);
	all_map = get_map(&data);
	check_for_texture(all_map, &data);
	check_texture(all_map);
	data.map.map = &all_map[data.map.start_map];
	parse_map(&data);
}
