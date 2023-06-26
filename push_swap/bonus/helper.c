/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 09:28:37 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:46:48 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*list_to_tab(t_list *stack, int size)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * size);
	while (i < size)
	{
		tab[i] = stack->content;
		stack = stack->next;
		i++;
	}
	return (tab);
}

void	init_stack(t_list **stack_a, int *array, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		ft_lstadd_back(stack_a, ft_lstnew(array[i]));
		i++;
	}
}

void	ft_free_split(char **split, char *str, int ac)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	if (ac > 2)
		free(str);
}

char	*joined_args(int ac, char **av)
{
	int		i;
	int		j;
	char	*str;

	i = 2;
	j = 0;
	str = ft_strdup(av[1]);
	while (i < ac)
	{
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, av[i]);
		i++;
	}
	return (str);
}

void	parse_int(int *tab, int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		if (!ft_str_is_numeric(av[i]))
			ft_error();
		tab[i] = ft_atoi(av[i]);
		j = 0;
		while (j < i)
		{
			if (tab[j] == tab[i])
				ft_error();
			j++;
		}
		i++;
	}
}
