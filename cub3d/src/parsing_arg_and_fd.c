/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg_and_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baptiste <baptiste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:58:19 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 11:55:16 by baptiste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

int open_fd(t_game *data, char **argv)
{
	data->fd = open(argv[1], __O_DIRECTORY);
	if (data->fd < 0)
	{
		printf("error: %d, is a directory\n", data->fd);
		close(data->fd);
		return (1);
	}
	data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0 || data->fd > 1028)
	{
		printf("error\n");
		close(data->fd);
		return (1);
	}
	return (0);
}

void	check_cub_argv(char *argv)
{
	int	size_argv;

	size_argv = ft_strlen(argv);
	if ((size_argv >= 4) && (ft_strcmp(argv + size_argv - 4, ".cub") == 0))
		return ;
	write(2, "Error:\nThe map should end with .ber\n", 36);
	exit(0);
}
