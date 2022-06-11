/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:30:10 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 19:11:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_b(t_stacks *stacks, int index)
{
	t_stack	*temp;
	int		i;
	int		j;

	j = stacks->b_size / 2;
	i = 0;
	temp = stacks->b_tail;
	while (1)
	{
		if (temp->index == index)
			break ;
		temp = temp->next;
		i++;
	}
	if (i == 0)
		rrb(stacks, 0);
	else if (i == stacks->b_size)
		return ;
	else if (i < j)
		drrb(stacks, i + 1);
	else
		drb(stacks, stacks->b_size - i);
}

void	rotate_a(t_stacks *stacks, int i)
{
	if (i == 0)
		rra(stacks, 0);
	else if (i == stacks->a_size)
		return ;
	else if (i < (stacks->a_size / 2))
		drra(stacks, i + 1);
	else
		dra(stacks, stacks->a_size - i);
}

void	rotate_rr(t_stacks *stacks, int mode)
{
	t_stack	*temp;

	if (mode == 0)
		ra(stacks, 0);
	else if (mode == 1)
	{
		temp = forward_increment(stacks->a_tail, stacks->a_size);
		if (temp->out == false && stacks->a_size >= 1 && stacks->b_size >= 1)
			rr(stacks, 0);
		else
			rb(stacks, 0);
	}
}
