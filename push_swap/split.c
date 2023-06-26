/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:37 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 02:37:37 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_strs(char const *str, char sep)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i])
			count++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (count);
}

size_t	len_str(char const *str, char sep)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

char	**ft_free(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(str[i++]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s)
		return (0);
	tab = malloc((count_strs(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	i = 0;
	j = 0;
	while (i < count_strs(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		len = len_str(s + j, c);
		tab[i] = ft_substr(s + j, 0, len);
		if (!tab[i])
			return (ft_free(tab, i));
		j += len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
