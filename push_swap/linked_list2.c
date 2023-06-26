/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:00:50 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:27:07 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*elem_index(t_list **stack, int index)
{
	t_list	*tmp_stack;
	int		i;

	tmp_stack = *stack;
	i = 0;
	while (tmp_stack && i < index)
	{
		i++;
		tmp_stack = tmp_stack->next;
	}
	if (tmp_stack)
		return (tmp_stack);
	return (NULL);
}

t_list	*ft_lstlast(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	lst_min_position(t_list *stack)
{
	int	min;
	int	i;
	int	position;

	i = 0;
	min = stack->content;
	position = 0;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			position = i;
		}
		stack = stack->next;
		i++;
	}
	return (position);
}
