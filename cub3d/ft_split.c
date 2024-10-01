/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:45 by bdany             #+#    #+#             */
/*   Updated: 2024/10/01 15:40:37 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if ((size * count > INT32_MAX) || (size > UINT16_MAX && count > UINT16_MAX))
		return (NULL);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}

int	ft_count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s != '\0' && *s == c)
		s++;
	while (s[i])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i + 1] == 0 && s[i] != c))
			count ++;
		i++;
	}
	return (count);
}

static char	**free_word(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**malloc_tab(char **tab, const char *s, char c)
{
	int	i;
	int	m;
	int	t;

	t = 0;
	i = 0;
	while (t < ft_count_word(s, c) && s[i])
	{
		m = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			m++;
		}
		tab[t] = ft_substr(s, i - m, m);
		if (!tab[t])
			return (free_word(tab));
		t++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = ft_calloc(sizeof(char *), ft_count_word(s, c) + 1);
	if (!tab)
		return (NULL);
	tab = malloc_tab(tab, s, c);
	if (!tab)
		return (NULL);
	return (tab);
}