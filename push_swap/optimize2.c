/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:18:37 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:42:27 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimiser4(int **optimized, int *moves, int size_a, int size_b)
{
	if (moves[1] >= ft_abs(moves[0]))
	{
		optimized[0][0] = ft_abs(moves[0]);
		optimized[0][1] = moves[0] + moves[1];
		optimized[1][0] = 3;
		optimized[1][1] = 2;
	}
	else if (size_b - moves[1] <= moves[0] + size_a)
	{
		optimized[0][0] = size_a - moves[1];
		optimized[0][1] = moves[0] + size_a - (size_b - moves[1]);
		optimized[1][0] = -3;
		optimized[1][1] = -1;
	}
	else
	{
		optimized[0][0] = moves[0] + size_a;
		optimized[0][1] = moves[1];
		optimized[1][0] = -1;
		optimized[1][1] = 2;
	}
}

void	optimiser5(int **optimized, int *moves, int size_b)
{
	optimized[0][0] = moves[1] + size_b * ft_isbigger(0, moves[1]);
	optimized[0][1] = 0;
	optimized[1][1] = 0;
	optimized[1][0] = 2 + (-4 * ft_isbigger(0, moves[1]));
}

void	optimiser6(int **optimized, int *moves, int size_a)
{
	optimized[0][0] = moves[0] + size_a * ft_isbigger(0, moves[0]);
	optimized[0][1] = 0;
	optimized[1][1] = 0;
	optimized[1][0] = 1 + (-2 * ft_isbigger(0, moves[0]));
}

void	optimiser7(int **optimized)
{
	optimized[0][0] = 0;
	optimized[0][1] = 0;
	optimized[1][0] = 0;
	optimized[1][1] = 0;
}
