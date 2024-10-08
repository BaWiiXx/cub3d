/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:43:16 by egomez            #+#    #+#             */
/*   Updated: 2024/10/04 19:12:18 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char **argv)
{
    t_data data;
    if (argc != 2)
	{
		write(2, "Error invalid map!\n", 19);
		return (1);
	}
    check_cub_argv(argv[1]);
	open_fd(&data, argv);
	data.map = get_map(data.fd);
	check_texture();
    check_map(&data);
}
