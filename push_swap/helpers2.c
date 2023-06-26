/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:21:29 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:38:34 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	filter_a(t_list **stack_a, t_list **stack_b, int n)
{
	int	i;
	int	*tab;
	int	*sequence;

	i = 0;
	tab = list_to_tab(*stack_a, n);
	sequence = sequence_tab(tab, n);
	while (i < n)
	{
		if (sequence[i] == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	free(sequence);
	free(tab);
}

void	place_helper(t_list **stack_b, int **tab, int i, int size_a)
{
	int		j;
	t_list	*b_i;

	b_i = elem_index(stack_b, i);
	if (tab[1][i] < min_tab(tab[0], size_a))
	{
		b_i->place = min_tab_index(tab[0], size_a);
		return ;
	}
	if (tab[1][i] > max_tab(tab[0], size_a))
	{
		b_i->place = (max_tab_index(tab[0], size_a) + 1) % size_a;
		return ;
	}
	if (tab[1][i] < tab[0][0] && tab[1][i] > tab[0][size_a - 1])
	{
		b_i->place = 0;
		return ;
	}
	j = 0;
	while (++j < size_a)
		if (tab[1][i] > tab[0][j - 1] && tab[1][i] < tab[0][j])
			b_i->place = j;
}

void	ft_place(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		**holder;
	t_list	*element;

	i = -1;
	element = elem_index(stack_b, i);
	holder = malloc(sizeof(int *) * 2);
	holder[0] = list_to_tab(*stack_a, ft_lstsize(*stack_a));
	holder[1] = list_to_tab(*stack_b, ft_lstsize(*stack_b));
	while (++i < ft_lstsize(*stack_b))
		place_helper(&element, holder, i, ft_lstsize(*stack_a));
	free(holder[0]);
	free(holder[1]);
	free(holder);
}
