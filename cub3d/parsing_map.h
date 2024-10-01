/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:35:35 by bdany             #+#    #+#             */
/*   Updated: 2024/10/01 16:03:00 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// les char valid
int	is_char_valid(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E'
     || c == '0' || c == '1' || c == ' ' || c == '\n' || c == '\0');
}

int is_whitespaces(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '9' && str[i] <= '13' || str[i] == '32')
			i++;
		else
			return (1);
	}
	return (0);
}

int is_line_valid(char *str)
{
	int i;

	while (str[i])
	{
		if(!is_char_valid(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int check_count_texture(t_data *data)
{
	if (data->texture->count_we != 1 || data->texture->count_so != 1 || data->texture->count_no != 1
		|| data->texture->count_ea != 1 || data->texture->count_f != 1 || data->texture->count_c != 1)
	{
		printf("error: texture is not good");
		return (1);
	}
	return (0);
}

int check_for_texture(t_data *data)
{
	int i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strncmp(data->map[i], "NO ", 3))
			data->texture->count_no++;
		if (ft_strncmp(data->map[i], "SO ", 3))
			data->texture->count_so++;
		if (ft_strncmp(data->map[i], "EA ", 3))
			data->texture->count_ea++;
		if (ft_strncmp(data->map[i], "WE ", 3))
			data->texture->count_we++;
		if (ft_strncmp(data->map[i], "f ", 2))
			data->texture->count_f++;
		if (ft_strncmp(data->map[i], "c ", 2))
			data->texture->count_c++;
		i++;
	}
}



static int	validate_line(char *line, t_data *map)
{
	int	j;

	if (line[0] != '1' && line[0] != ' ')
		return (write(2,"error: invalid map\n", 21));
	j = ft_strlen(line) - 1;
	if (line[j] != '1')
			return (write(2,"error: invalid map\n", 21));
	if (is_line_valid(line) == 0 || is_whitespaces(line) == 1)
			return (write(2,"error: invalid map\n", 21));
	if (is_direction_valid < 1)
			return (write(2,"error: invalid map\n", 21));
	return (0);
}

int check_map(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (data->map[i])
	{
		
	}
	return (0);
}