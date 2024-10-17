/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:39:45 by bdany             #+#    #+#             */
/*   Updated: 2024/10/17 17:29:21 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = s[i + start];
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static int	ft_count_word(const char *s, char c)
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
