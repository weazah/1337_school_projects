/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:08:53 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 22:56:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_stacks *stacks, int mode)
{
	if (stacks->a_tail && stacks->a_size > 0)
		stacks->a_tail = stacks->a_tail->previous;
	if (mode == 0)
		ft_printf("ra\n");
}

void	rb(t_stacks *stacks, int mode)
{
	if (stacks->b_tail && stacks->b_size > 0)
		stacks->b_tail = stacks->b_tail->previous;
	if (mode == 0)
		ft_printf("rb\n");
}

void	rr(t_stacks *stacks, int sig)
{
	if (stacks->a_tail && stacks->a_tail
		&& stacks->a_size > 0 && stacks->b_size > 0)
	{
		ra(stacks, 1);
		rb(stacks, 1);
	}
	if (sig == 0)
		ft_printf("rr\n");
}

void	rra(t_stacks *stacks, int mode)
{
	if (stacks->a_tail && stacks->a_size > 0)
		stacks->a_tail = stacks->a_tail->next;
	if (mode == 0)
		ft_printf("rra\n");
}

void	rrb(t_stacks *stacks, int mode)
{
	if (stacks->b_tail && stacks->b_size > 0)
		stacks->b_tail = stacks->b_tail->next;
	if (mode == 0)
		ft_printf("rrb\n");
}
