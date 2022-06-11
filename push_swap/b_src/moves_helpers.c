/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:09:06 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:44:58 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

t_stack	*forward_increment(t_stack *node, int times)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = node;
	if (node)
	{
		while (i < times)
		{
			temp = temp->next;
			i++;
		}
	}
	return (temp);
}

t_stack	*init_push(t_stack *node)
{
	node->next = node;
	node->previous = node;
	return (node);
}

t_stack	*delete_node(t_stack *tail, int size)
{
	t_stack	*node;
	t_stack	*node_2;

	node = NULL;
	if (size > 0)
	{
		node = forward_increment(tail, size);
		node->next = NULL;
		node->previous = NULL;
		node_2 = forward_increment(tail, size - 1);
		node_2->next = tail;
		tail->previous = node_2;
	}
	else if (size == 0)
	{
		node = tail;
		node->next = NULL;
		node->previous = NULL;
	}
	return (node);
}

void	add_node(t_stack *tail, int size, t_stack *node)
{
	t_stack	*head;

	if (size > -1)
	{
		head = forward_increment(tail, size);
		head->next = node;
		tail->previous = node;
		node->next = tail;
		node->previous = head;
	}
}
