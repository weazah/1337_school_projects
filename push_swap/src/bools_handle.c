/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bools_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:37:05 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 22:39:50 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	bool_count(t_stack *stack, int times)
{
	t_stack	*temp;
	int		i;
	int		count;

	i = 0;
	count = 0;
	temp = stack;
	while (i < times + 1)
	{
		if (temp->out == true)
			count++;
		temp = temp->next;
		i++;
	}
	return (count);
}

void	flush_bools(t_stacks *stacks)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = stacks->a_tail;
	while (stacks->a_size > -1 && i < stacks->a_size)
	{
		temp->out = false;
		temp = temp->next;
		i++;
	}
	i = 0;
	temp = stacks->b_tail;
	while (stacks->b_size > -1 && i < stacks->b_size)
	{
		temp->out = false;
		temp = temp->next;
		i++;
	}
}
