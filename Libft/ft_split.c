/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:19:57 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/13 10:23:07 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

static char	*get_word(char **tab, char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (s[i] != c && s[i])
		i++;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (0);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	*tab = word;
	return ((char *)(s + i));
}

static void	free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		i;

	if (!s)
		return (0);
	words = count_words(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	while (i < words)
	{
		s = get_word(&tab[i], s, c);
		if (!tab[i])
		{
			free_tab(tab, i);
			return (0);
		}
		i++;
	}
	tab[i] = 0;
	return (tab);
}
