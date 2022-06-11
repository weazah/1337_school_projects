/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:52:40 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/25 23:15:22 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static	int	char_set(char c)
{
	if ((c <= '9' && c >= '0') || c == '-' || c == '+')
		return (1);
	return (0);
}

static	int	is_included(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][0] == 0)
			return (0);
		while (av[i][j])
		{
			if (char_set(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static	int	char_set_pos(char *num)
{
	int	i;
	int	exist;
	int	len;

	i = 0;
	exist = 0;
	len = ft_strlen(num);
	while (num[i])
	{
		if (num[i] == '+' || num[i] == '-')
			exist++;
		i++;
	}
	if ((exist == 1 && num[0] == '-' && len != 1)
		|| (exist == 1 && num[0] == '+' && len != 1) || exist == 0)
	{
		return (1);
	}
	else
		return (0);
}

static	int	is_right(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (char_set_pos(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_vals(char **av)
{
	int	i;
	int	j;

	i = is_included(av);
	j = is_right(av);
	if (i == 0 || j == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	return (1);
}
