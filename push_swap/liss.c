/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:08 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 02:37:08 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sequence_length(int *tab, int ac, int index)
{
	int	i;
	int	j;
	int	size;

	j = index;
	i = 0;
	size = 0;
	while (i < ac)
	{
		if (tab[j] >= tab[index])
		{
			size++;
			index = j;
		}
		j = (j + 1) % ac;
		i++;
	}
	return (size);
}

int	sequence_head(int *tab, int ac)
{
	int	i;
	int	size;
	int	max;
	int	head;

	i = 0;
	max = 0;
	while (i < ac)
	{
		size = sequence_length(tab, ac, i);
		if (size >= max)
		{
			max = size;
			head = tab[i];
		}
		i++;
	}
	return (head);
}

int	*sequence_tab(int *tab, int ac)
{
	int	i;
	int	j;
	int	*sequence;
	int	index;

	i = -1;
	index = 0;
	while (tab[index] != sequence_head(tab, ac))
		index++;
	j = index;
	sequence = malloc(sizeof(int) * ac);
	while (++i < ac)
	{
		if (tab[j] >= tab[index])
		{
			sequence[j] = 1;
			index = j;
		}
		else
			sequence[j] = 0;
		j = (j + 1) % ac;
	}
	return (sequence);
}
