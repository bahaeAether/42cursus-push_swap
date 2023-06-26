/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:14 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:48:39 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_limit(long n, int sign)
{
	n *= sign;
	return (n >= INT_MIN && n <= INT_MAX);
}

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	*parse_args(t_list **stack_a, int ac, char **av)
{
	char	**split;
	char	*str;
	int		*tab;
	int		i;

	i = 2;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ac > 2)
	{
		str = joined_args(ac, av);
		av[1] = str;
	}
	split = ft_split(av[1], ' ');
	if (!split[0])
		ft_error();
	i = 0;
	while (split[i])
		i++;
	tab = malloc(sizeof(int) * i);
	parse_int(tab, i, split);
	ft_free_split(split, str, ac);
	*stack_a = ft_lstnew(tab[0]);
	init_stack(stack_a, tab, i);
	return (tab);
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
