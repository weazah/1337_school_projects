/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_qs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:56:25 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:01:09 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

void	swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static	int	sort_call(int *arr, int low, int high)
{
	int	pivot;
	int	i;

	pivot = arr[high];
	i = (low - 1);
	while (low < high)
	{
		if (arr[low] < pivot)
		{
			i++;
			if (i != low)
				swap(&arr[i], &arr[low]);
		}
		low++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort(int *arr, int low, int high)
{
	int	part;

	if (low >= high)
		return ;
	part = sort_call(arr, low, high);
	quicksort(arr, low, part - 1);
	quicksort(arr, part + 1, high);
}
