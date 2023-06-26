/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:55:06 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:54:44 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

ssize_t	ft_putstr_fd(char *s, int fd)
{
	ssize_t	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
		ft_putchar_fd(s[i], fd);
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	n;

	if (str == NULL)
		return (0);
	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		if (!ft_limit(n, sign))
			ft_error();
		i++;
	}
	return (sign * n);
}
