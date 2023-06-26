/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:37:25 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:45:24 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a);
}

void	sort_three(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		sa(stack_a);
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->next->content < (*stack_a)->next->next->content)
		ra(stack_a);
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content
		&& (*stack_a)->next->content > (*stack_a)->next->next->content)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		rra(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min_position;

	min_position = lst_min_position(*stack_a);
	if (min_position == 1)
		sa(stack_a);
	else if (min_position == 2)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (min_position == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min_position;

	min_position = lst_min_position(*stack_a);
	if (min_position < 3)
		while (min_position--)
			ra(stack_a);
	else
		while (min_position++ < 5)
			rra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_list(t_list **stack_a)
{
	int		size;
	t_list	*stack_b;

	stack_b = NULL;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, &stack_b);
	else if (size == 5)
		sort_five(stack_a, &stack_b);
	else
		ft_sort(stack_a, &stack_b);
}
