/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:41:05 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:10:12 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	indexing_func(t_stack *stack_a, int *array, int len)
{
	int		i;
	t_stack	*temp;

	temp = stack_a;
	i = 0;
	while (i < len)
	{
		while (temp->num != array[i])
			temp = temp->next;
		temp->index = i;
		i++;
	}
}
