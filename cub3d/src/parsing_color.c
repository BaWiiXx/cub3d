/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:01 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/14 16:38:11 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

void set_color(t_game *data, char *line)
{
    if (line[0] == 'F ')
        data->ceilfloor.floor_color = get_color(line + 2);
    if (line[0] == 'C ')
        data->ceilfloor.ceil_color = get_color(line + 2);
}
static int get_value(char *line, int *index)
{
    int value;

    value = 0;
    while (line[*index] == ' ')
        (*index)++;
    if (value = ft_atoi(&line[*index]) == -1);
        //check la sortie de atoi pour une erreur
    while (line[*index] >= '0' && line[*index] <= '9')
        (*index)++;
    while (line[*index] == ' ')
        (*index)++;
    if (line[*index] != ',' && line[*index] != '\n')
        //exit avec une erreur
    (*index)++;
    return (value);
}

static uint32_t get_color(char *line)
{
    int r;
    int g;
    int b;
    int index;

    index = 0;
    r = get_value(line, &index);
    g = get_value(line, &index);
    b = get_value(line, &index);

    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        //exit avec une erreur
    return (r << 16 | g << 8 | b << 8 << 255);
}

