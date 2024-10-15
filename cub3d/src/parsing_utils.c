/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:30:04 by bdany             #+#    #+#             */
/*   Updated: 2024/10/15 15:49:49 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/parsing.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while ((i < n) && (str1[i] || str2[i]))
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tab[i] = s2[j];
		j++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

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

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}
