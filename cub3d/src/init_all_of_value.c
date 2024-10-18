/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_of_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:49:19 by bdany             #+#    #+#             */
/*   Updated: 2024/10/18 18:19:38 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void init_all_of_value(t_game *data)
{
	data->map.line = 0;
	data->map.start_map = 0;
	data->ceilfloor.ceil_color = 0;
	data->ceilfloor.floor_color = 0;
	data->texture.count_c = 0;
	data->texture.count_f = 0;
	data->texture.count_no = 0;
	data->texture.count_we = 0;
	data->texture.count_so = 0;
	data->texture.count_ea = 0;
}

void init_texture(t_text *texture)
{
	texture->count_c = 0;
	texture->count_f = 0;
	texture->count_no = 0;
	texture->count_we = 0;
	texture->count_so = 0;
	texture->count_ea = 0;
}
