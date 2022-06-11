/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:15:39 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 22:57:32 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	rrr(t_stacks *stacks, int sig)
{
	if (stacks->a_tail && stacks->a_tail
		&& stacks->a_size > 0 && stacks->b_size > 0)
	{
		rra(stacks, 1);
		rrb(stacks, 1);
	}
	if (sig == 0)
		ft_printf("rrr\n");
}
