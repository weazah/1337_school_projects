/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:59:49 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 19:10:31 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	flag_to_out(t_stacks *stacks, int *array, int total)
{
	int		i;
	int		piv;
	t_stack	*temp;

	if (total >= 499)
		piv = stacks->a_size / 5;
	else
		piv = stacks->a_size / 3;
	temp = stacks->a_tail;
	i = 0;
	while (i < stacks->a_size + 1)
	{
		if (temp->num <= array[piv])
			temp->out = true;
		temp = temp->next;
		i++;
	}
	return (piv);
}

int	flaged_to_b(t_stacks *stacks, int *array, int piv)
{
	int		count;
	int		i;
	t_stack	*temp;

	count = bool_count(stacks->a_tail, stacks->a_size);
	i = 0;
	while (i != count)
	{
		temp = forward_increment(stacks->a_tail, stacks->a_size);
		if (temp->out == true)
		{
			if (temp->num <= array[piv / 2])
			{
				pb(stacks, 0);
				rotate_rr(stacks, 1);
			}
			else
				pb(stacks, 0);
			i++;
		}
		else
			rotate_rr(stacks, 0);
	}
	return (count);
}

void	reverse_push(t_stacks *stacks)
{
	t_stack	*temp;

	while (stacks->b_size != -1)
	{
		temp = forward_increment(stacks->a_tail, stacks->a_size);
		rotate_b(stacks, temp->index - 1);
		pa(stacks, 0);
	}
}

void	push_smallest(t_stacks *stacks)
{
	int		i;
	int		j;
	int		count;
	t_stack	*temp;

	if (stacks->a_size == 4)
		i = 2;
	else
		i = 1;
	j = 0;
	while (i)
	{
		temp = stacks->a_tail;
		count = 0;
		while (temp->index != j)
		{
			temp = temp->next;
			count++;
		}
		rotate_a(stacks, count);
		pb(stacks, 0);
		j++;
		i--;
	}
}

void	push_swap(t_stacks *stacks, int *array)
{
	int	total;
	int	count;
	int	piv;

	count = 0;
	total = stacks->a_size;
	flush_bools(stacks);
	if (total <= 2)
		three_sort(stacks);
	else if (total <= 4)
		five_sort(stacks);
	else if (total > 4)
	{
		while (stacks->a_size > 0)
		{
			piv = flag_to_out(stacks, array + count, total);
			count += flaged_to_b(stacks, array + count, piv);
			flush_bools(stacks);
		}
		reverse_push(stacks);
	}
	free(array);
	st_free(stacks);
}
