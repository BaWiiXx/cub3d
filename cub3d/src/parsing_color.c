/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:26:01 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/04 18:12:41 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

uint32_t check_color(int r, int g, int b)
{
    return (r << 16 | g << 8 | b << 8 | 255);
}
void check_value(int r, int g, int b)
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
    {
        printf("error, wrong color value.\n");
        exit(EXIT_FAILURE);
    }
}

