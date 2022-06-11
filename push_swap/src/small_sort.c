/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:33:39 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 22:36:47 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	five_sort(t_stacks *stacks)
{
	push_smallest(stacks);
	three_sort(stacks);
	pa(stacks, 0);
	pa(stacks, 0);
}

void	three_sort(t_stacks *stack)
{
	t_stack	*tail;

	tail = stack->a_tail->previous;
	if (tail->num > tail->previous->num)
		sa(stack, 0);
	tail = stack->a_tail->previous;
	if (tail->next->num < tail->previous->num)
	{
		rra(stack, 0);
		if (tail->next->num > tail->num)
			sa(stack, 0);
	}
}
