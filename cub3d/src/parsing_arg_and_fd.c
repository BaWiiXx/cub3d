/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_and_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:58:19 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/18 16:05:09 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void open_fd(t_game *data, char **argv)
{
	data->fd = open(argv[1], __O_DIRECTORY);
	if (data->fd > 0)
	{
		printf("error: %d, is a directory\n", data->fd);
		close(data->fd);
		exit(EXIT_FAILURE);
	}
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0 || data->fd > 1024)
	{
		printf("error\n");
		close(data->fd);
		exit(EXIT_FAILURE);
	}
}

void	check_cub_argv(char *argv)
{
	int	size_argv;

	size_argv = ft_strlen(argv);
	if ((size_argv >= 4) && (ft_strcmp(argv + size_argv - 4, ".cub") == 0))
		return ;
	write(2, "error: the map should end with .cub\n", 36);
	exit(0);
}
