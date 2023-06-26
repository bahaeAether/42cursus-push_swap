/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baboulou <baboulou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 06:28:24 by baboulou          #+#    #+#             */
/*   Updated: 2023/06/19 06:28:44 by baboulou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_malloc(void)
{
	ft_putstr_fd("Error: Failed to allocate memory\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_stack(void)
{
	ft_putstr_fd("Error: Failed to load Stack\n", 2);
	exit(EXIT_FAILURE);
}
