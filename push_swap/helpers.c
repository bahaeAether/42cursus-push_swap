/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:19:13 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:20:01 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	min_tab(int *tab, int size)
{
	int	i;
	int	min;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	max_tab(int *tab, int size)
{
	int	i;
	int	max;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	min_tab_index(int *tab, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = tab[0];
	index = 0;
	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max_tab_index(int *tab, int size)
{
	int	i;
	int	max;
	int	index;

	i = 0;
	max = tab[0];
	index = 0;
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}
