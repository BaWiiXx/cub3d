/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:07:22 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/14 17:48:55 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

// char **get_map(int fd)
// {
// 	char **map;
// 	char *line;
// 	char *tmp;

// 	map = NULL;
// 	tmp = NULL;
// 	line = get_next_line(fd);
// 	if(!line)
// 		return(NULL);
// 	while(tmp != NULL)
// 	{
// 		line = ft_strjoin(line, tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	map = ft_split(line, '\n');
// 	free(line);
// 	free(tmp);
// 	return (map);
// }

int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

int check_line(char *str, t_game *data)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (is_char_valid(str[i]) == 'N' || is_char_valid(str[i]) == 'S'
			|| is_char_valid(str[i]) == 'E' || is_char_valid(str[i]) == 'W')
			data->texture.direction++;
		if(!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int size_map (int fd,t_game *data)
{
	char *line;
	int	count_line;
	int found_map;

	found_map = 0;
	count_line = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!found_map)
		{
			if (line[0] != '\n')
				found_map = 1;
		}
		if (found_map)
		{
			if (check_line(line, data) == 0)
				count_line++;
			else
			free(line);
		}
	}
	return (count_line);
}
