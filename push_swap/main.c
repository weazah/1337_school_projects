/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:49:44 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 18:56:00 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	special_func(char	**arg_list, int given_l)
{
	int			*array;
	int			len;
	t_stack		*stack_a;
	t_stacks	*stacks;

	len = 0;
	stack_a = NULL;
	if (check_vals(arg_list) == 0)
		return ;
	if (given_l == 0)
		len = twd_len(arg_list);
	else
		len = given_l;
	array = get_vals(arg_list, len);
	if (!array)
		return ;
	stack_a = convert_array(arg_list, array);
	if (stack_a == NULL)
		return ;
	indexing_func(stack_a, array, len);
	stacks = init_stacks(stack_a, len, array);
	if (!stacks)
		return (free(array));
	push_swap(stacks, array);
}

int	main(int ac, char **av)
{
	char	**args;

	if (ac > 1)
	{
		if (ac == 2)
		{
			args = ft_split(av[1], ' ');
			if (!args)
				return (0);
			special_func(args, 0);
			d_free(args);
		}
		else
			special_func(av + 1, ac - 1);
	}
}
