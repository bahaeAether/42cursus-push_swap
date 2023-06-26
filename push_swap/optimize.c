/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:17:14 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:42:22 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*moves_to_place(int i, int j, int size_a, int size_b)
{
	int	*vector;

	vector = malloc(sizeof(int) * 2);
	vector[0] = i;
	vector[1] = j;
	if (i > size_a / 2)
		vector[0] *= -1;
	if (j > size_b / 2)
		vector[1] *= -1;
	return (vector);
}

int	**moves_optimizer(int *moves, int size_a, int size_b)
{
	int	**optimized;

	optimized = malloc(sizeof(int *) * 2);
	optimized[0] = malloc(sizeof(int) * 2);
	optimized[1] = malloc(sizeof(int) * 2);
	if (moves[0] > 0 && moves[1] > 0)
		optimiser1(optimized, moves);
	else if (moves[0] < 0 && moves[1] < 0)
	{
		moves[0] += size_a;
		moves[1] += size_b;
		optimiser2(optimized, moves);
	}
	else if (moves[0] > 0 && moves[1] < 0)
		optimiser3(optimized, moves, size_a, size_b);
	else if (moves[1] > 0 && moves[0] < 0)
		optimiser4(optimized, moves, size_a, size_b);
	else if (moves[0] == 0 && moves[1] != 0)
		optimiser5(optimized, moves, size_b);
	else if (moves[1] == 0 && moves[0] != 0)
		optimiser6(optimized, moves, size_a);
	else
		optimiser7(optimized);
	free(moves);
	return (optimized);
}

void	optimiser1(int **optimized, int *moves)
{
	optimized[0][0] = min_tab(moves, 2);
	optimized[0][1] = ft_abs(moves[0] - moves[1]);
	optimized[1][0] = 3;
	optimized[1][1] = 1 + ft_isbigger(moves[1], moves[0]);
}

void	optimiser2(int **optimized, int *moves)
{
	optimized[0][0] = min_tab(moves, 2);
	optimized[0][1] = ft_abs(moves[0] - moves[1]);
	optimized[1][0] = -3;
	optimized[1][1] = -1 - ft_isbigger(moves[1], moves[0]);
}

void	optimiser3(int **optimized, int *moves, int size_a, int size_b)
{
	if (moves[0] >= ft_abs(moves[1]))
	{
		optimized[0][0] = ft_abs(moves[1]);
		optimized[0][1] = moves[0] + moves[1];
		optimized[1][0] = 3;
		optimized[1][1] = 1;
	}
	else if (size_a - moves[0] <= moves[1] + size_b)
	{
		optimized[0][0] = size_a - moves[0];
		optimized[0][1] = moves[1] + size_b - (size_a - moves[0]);
		optimized[1][0] = -3;
		optimized[1][1] = -2;
	}
	else
	{
		optimized[0][0] = moves[0];
		optimized[0][1] = moves[1] + size_b;
		optimized[1][0] = 1;
		optimized[1][1] = -2;
	}
}
