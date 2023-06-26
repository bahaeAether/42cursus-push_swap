/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 08:51:09 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:08:59 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_read(char *buffer, int fd)
{
	char	*holder;
	ssize_t	n;

	holder = malloc(BUFFER_SIZE + 1);
	if (!holder)
	{
		free(buffer);
		return (0);
	}
	holder[0] = 0;
	n = 1;
	while (!ft_strchr(buffer, '\n') && n != 0)
	{
		n = read(fd, holder, BUFFER_SIZE);
		if (n == -1)
		{
			free(holder);
			free(buffer);
			return (0);
		}
		buffer = ft_strnjoin(buffer, holder, n);
	}
	free(holder);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		return (ft_substr(buffer, 0, i + 1));
	else
		return (ft_substr(buffer, 0, i));
}

char	*ft_update(char *buffer)
{
	char	*holder;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	holder = ft_substr(buffer, i + 1, SIZE_MAX);
	free(buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	char		*holder;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (0);
	holder = ft_get_line(buffer);
	buffer = ft_update(buffer);
	if (holder && holder[0] == '\0')
	{
		free(buffer);
		free(holder);
		return (0);
	}
	return (holder);
}
