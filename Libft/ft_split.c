/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:19:57 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/09 20:25:15 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int		ft_count_words(char const *s, char c);
static	size_t	ft_strlenc(const char *s, char c);
static	void		*ft_free_tab(char **tab, int i);

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		j;

	word = ft_count_words(s, c);
	tab = (char **) malloc((word + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (i < word)
	{
		while (*s == c && *s)
			s++;
		tab[i] = (char *) malloc((ft_strlenc(s, c) + 1) * sizeof(char));
		if (!tab[i])
			return (ft_free_tab(tab, i));
		j = 0;
		while (*s != c && *s)
			tab[i][j++] = *s++;
		tab[i][j] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

static size_t	ft_strlenc(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static	void	*ft_free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (0);
}

static	int	ft_count_words(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			word++;
			while (*s != c && *s)
			{
				s++;
			}
		}
		else
			s++;
	}
	return (word);
}
