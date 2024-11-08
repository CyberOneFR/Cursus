/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ethebaul <ethebaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 01:54:26 by ethebaul          #+#    #+#             */
/*   Updated: 2024/11/08 02:15:51 by ethebaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (s1[++i])
	{
		j = -1;
		while (set[++j])
			if (s1[i] == set[j])
				k++;
	}
	str = (char *) malloc((i - k + 1) * sizeof(char));
	if (!str)
		return (0);
	while (i - k >= 0)
		while (set[j])
	return (str);
}
