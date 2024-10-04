/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/04 17:38:42 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

char **get_map(int fd)
{
	char **map;
	char *line;
	char *tmp;

	map = NULL;
	tmp = NULL;
	line = get_next_line(fd);
	if(!line)
		return(NULL);
	while(tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	free(tmp);
	return (map);
}

// char	**get_map(char *str, t_data *data)
// {
// 	unsigned int	i;
// 	char			*temp;

// 	i = 0;
// 	data->fd = open(str, O_RDONLY);
// 	if (data->fd == '\0')
// 		exit(0);
// 	if (!data->map)
// 		return (NULL);
// 	while (i < data->line)
// 	{
// 		temp = get_next_line(data->fd);
// 		data->map[i] = ft_strdup(temp);
// 		free(temp);
// 		temp = NULL;
// 		i++;
// 	}
// 	close(data->fd);
// 	return (data->map);
// }