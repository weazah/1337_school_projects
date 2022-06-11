/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:47:34 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:08:52 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

static	int	*check_dup(int *array, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= len)
	{
		if (array[i] == array[j])
			return (arr_panic(array, len, 1));
		j++;
		i++;
	}
	return (array);
}

static	int	*is_arr_sorted(int *array, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (array[i] > array[j] && i <= len)
	{
		i++;
		j++;
	}
	if (i == len + 1)
		return (arr_panic(array, len, 3));
	return (array);
}

static	int	num_len(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	int	compare_len(char *num, int n)
{
	int	i;
	int	j;

	if ((num[0] == '-' && n > 0)
		|| ((num[0] == '+' || (num[0] >= '0' && num[0] <= 9)) && n < 0))
		return (0);
	i = ft_strlen(num);
	if (num[0] == '+')
		i--;
	j = num_len(n);
	if (j != i)
		return (0);
	return (1);
}

int	*get_vals(char **av, int len)
{
	int	*array;
	int	i;

	array = malloc(len * sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (av[i])
	{
		array[i] = ft_atoi(av[i]);
		if (compare_len(av[i], array[i]) == 0)
			return (arr_panic(array, len, 1));
		i++;
	}
	if (is_arr_sorted(array, i - 1) == 0)
		return (NULL);
	quicksort(array, 0, i - 1);
	array = check_dup(&array[0], i - 1);
	return (array);
}
