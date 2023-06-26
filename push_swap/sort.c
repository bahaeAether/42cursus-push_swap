/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:21 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:24:01 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update(int **optimized, int **best, int *min)
{
	if (optimized[0][1] + optimized[0][0] < *min)
	{
		*min = optimized[0][0] + optimized[0][1];
		ft_clone(best, optimized);
	}
}

int	**best_move(t_list **stack_a, t_list **stack_b)
{
	int	*moves;
	int	**optimized;
	int	**best;
	int	min;
	int	i;

	i = -1;
	ft_place(stack_a, stack_b);
	min = INT_MAX;
	best = ft_malloc_tab(2, 2);
	if (!best)
		ft_error_malloc();
	while (++i < ft_lstsize(*stack_b))
	{
		moves = moves_to_place(elem_index(stack_b, i)->place, i,
				ft_lstsize(*stack_a), ft_lstsize(*stack_b));
		optimized = moves_optimizer(moves, ft_lstsize(*stack_a),
				ft_lstsize(*stack_b));
		ft_update(optimized, best, &min);
		ft_free_int(optimized, 2);
	}
	return (best);
}

void	ft_adjust(t_list **stack_a)
{
	int	min_position;
	int	*tab;
	int	size;

	size = ft_lstsize(*stack_a);
	tab = list_to_tab(*stack_a, size);
	min_position = min_tab_index(tab, size);
	free(tab);
	if (min_position <= size / 2)
		while (min_position--)
			ra(stack_a);
	else
		while (min_position++ < size)
			rra(stack_a);
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	**moves;
	int	i;

	filter_a(stack_a, stack_b, ft_lstsize(*stack_a));
	while (ft_lstsize(*stack_b) > 0)
	{
		moves = best_move(stack_a, stack_b);
		i = -1;
		while (++i < moves[0][0])
			execute_move(moves[1][0], stack_a, stack_b);
		i = -1;
		while (++i < moves[0][1])
			execute_move(moves[1][1], stack_a, stack_b);
		pa(stack_a, stack_b);
		ft_free_int(moves, 2);
	}
	ft_adjust(stack_a);
}
