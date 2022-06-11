/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:25:58 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 22:29:47 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	dra(t_stacks *stacks, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		ra(stacks, 0);
		i++;
	}
}

void	drra(t_stacks *stacks, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		rra(stacks, 0);
		i++;
	}
}

void	drb(t_stacks *stacks, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		rb(stacks, 0);
		i++;
	}
}

void	drrb(t_stacks *stacks, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		rrb(stacks, 0);
		i++;
	}
}
