/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:49:53 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 18:57:13 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap_bonus.h"

int	error_move(t_stacks *stacks, int *array, int mode)
{
	if (mode == 0)
		ft_putstr_fd("error\n", 2);
	if (array)
		free(array);
	while (stacks->b_size != -1)
		pa(stacks, 1);
	st_free(stacks);
	return (0);
}

int	result_of_moves(t_stacks *stacks, int *array)
{
	if (st_is_sorted(stacks) == 1 && stacks->b_size == -1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (error_move(stacks, array, 1));
}

int	checker(t_stacks *stacks, int *array)
{
	char	*move;
	int		state;

	while (1)
	{
		move = get_next_line(0);
		if (!move)
			break ;
		state = this_move(move, stacks);
		free(move);
		if (state == 0)
			return (error_move(stacks, array, 0));
	}
	return (result_of_moves(stacks, array));
}

void	checker_func(char **arg_list, int given_l)
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
	stacks = init_stacks(stack_a, len, array);
	if (!stacks)
		return (free(array));
	checker(stacks, array);
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
			checker_func(args, 0);
			d_free(args);
		}
		else
			checker_func(av + 1, ac - 1);
	}
}
