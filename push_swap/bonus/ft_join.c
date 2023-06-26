/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:00:07 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:03:39 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, ft_strlen(s1) + 1);
	ft_strlcat(result, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	free((char *)s1);
	return (result);
}

char	*ft_strdup(char *src)
{
	char	*dup;

	dup = malloc(ft_strlen(src) + 1);
	ft_strlcpy(dup, src, ft_strlen(src) + 1);
	return (dup);
}
