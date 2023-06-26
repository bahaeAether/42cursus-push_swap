/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:43:11 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 09:13:20 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*stack_a;

	tab = parse_args(&stack_a, ac, av);
	if (is_sorted(tab, ft_lstsize(stack_a)))
		exit(EXIT_SUCCESS);
	free(tab);
	sort_list(&stack_a);
	return (0);
}
