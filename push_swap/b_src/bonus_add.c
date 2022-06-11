/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:07:29 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 19:05:35 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	three_move(char	*move, t_stacks *stacks)
{
	if (ft_strncmp(move, "rra", 3) == 0)
		return (rra(stacks, 1), 1);
	if (ft_strncmp(move, "rrb", 3) == 0)
		return (rrb(stacks, 1), 1);
	if (ft_strncmp(move, "rrr", 3) == 0)
		return (rrr(stacks, 1), 1);
	return (0);
}

int	this_move(char	*move, t_stacks	*stacks)
{
	int	i;

	i = ft_strlen(move);
	if (ft_strlen(move) == 4)
		return (three_move(move, stacks));
	else if (ft_strlen(move) == 3)
	{
		if (ft_strncmp(move, "sa", 2) == 0)
			return (sa(stacks, 1), 1);
		if (ft_strncmp(move, "sb", 2) == 0)
			return (sb(stacks, 1), 1);
		if (ft_strncmp(move, "ss", 2) == 0)
			return (ss(stacks, 1), 1);
		if (ft_strncmp(move, "pa", 2) == 0)
			return (pa(stacks, 1), 1);
		if (ft_strncmp(move, "pb", 2) == 0)
			return (pb(stacks, 1), 1);
		if (ft_strncmp(move, "ra", 2) == 0)
			return (ra(stacks, 1), 1);
		if (ft_strncmp(move, "rb", 2) == 0)
			return (rb(stacks, 1), 1);
		if (ft_strncmp(move, "rr", 2) == 0)
			return (rr(stacks, 1), 1);
	}
	return (0);
}

int	st_is_sorted(t_stacks *stacks)
{
	t_stack	*tail;
	int		i;
	int		size;

	tail = stacks ->a_tail;
	size = stacks->a_size;
	i = 0;
	while (i < size)
	{
		if (tail->num < tail->next->num)
			return (0);
		tail = tail->next;
		i++;
	}
	if (stacks->b_size == -1)
		return (1);
	return (0);
}
