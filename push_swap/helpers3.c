/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:22:52 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:24:11 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**ft_malloc_tab(int n, int m)
{
	int	i;
	int	**tab;

	i = 0;
	tab = malloc(sizeof(int *) * n);
	if (!tab)
		return (NULL);
	while (i < n)
	{
		tab[i] = malloc(sizeof(int) * m);
		if (!tab[i])
			return (NULL);
		i++;
	}
	return (tab);
}

void	ft_free_int(int **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(tab[i++]);
	free(tab);
}

void	ft_clone(int **clone, int **tab)
{
	clone[0][0] = tab[0][0];
	clone[0][1] = tab[0][1];
	clone[1][0] = tab[1][0];
	clone[1][1] = tab[1][1];
}

void	execute_move(int move, t_list **stack_a, t_list **stack_b)
{
	if (move == 1)
		ra(stack_a);
	else if (move == 2)
		rb(stack_b);
	else if (move == 3)
		rr(stack_a, stack_b);
	else if (move == -1)
		rra(stack_a);
	else if (move == -2)
		rrb(stack_b);
	else if (move == -3)
		rrr(stack_a, stack_b);
}
