/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:58:19 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/01 15:52:15 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

int check_fd(t_data *window)
{
		if (window->fd = open(window->fd, __O_DIRECTORY))
	{
		printf("error:%s, is a directory\n", window->fd);
		close(window->fd);
		return (1);
	}
	window->fd = open(window->fd, O_RDONLY);
	if (window->fd < 0)
	{
		printf("error files\n");
		close(window->fd);
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
