/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:37:42 by baptiste          #+#    #+#             */
/*   Updated: 2024/10/16 14:11:37 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}

int	is_whitespaces(char *str)
{
	int	i;

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

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*t;

	i = 0;
	t = (unsigned char *)s;
	while (i < n)
		t[i++] = (unsigned char)c;
	return (t);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	chr;

	chr = c;
	while (*s != '\0' && *s != chr)
		s++;
	if (*s == chr)
		return ((char *)s);
	return (0);
}
