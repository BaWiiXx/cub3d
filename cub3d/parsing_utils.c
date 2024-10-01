/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:30:04 by bdany             #+#    #+#             */
/*   Updated: 2024/10/01 15:48:49 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	s;
	int	m;

	i = 0;
	s = 1;
	m = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		m = m * 10 + (nptr[i] - '0');
		i++;
	}
	return (m * s);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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