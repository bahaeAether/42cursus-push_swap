/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:35:30 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 10:46:09 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	execute_moves(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error();
}

void	ft_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_moves(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*stack_a;
	t_list	*stack_b;

	tab = parse_args(&stack_a, ac, av);
	free(tab);
	ft_checker(&stack_a, &stack_b);
	tab = list_to_tab(stack_a, ft_lstsize(stack_a));
	if (is_sorted(tab, ft_lstsize(stack_a)) && ft_lstsize(stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free(tab);
	return (0);
}
