/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   managing_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:54:39 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 19:08:33 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap_bonus.h"

int	twd_len(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		i++;
	}
	return (i);
}

void	d_free(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
	args = NULL;
}

int	*arr_panic(int *array, int len, int mode)
{
	if (mode == 1)
		ft_printf("Error\n");
	if (mode == 3)
		ft_printf("OK\n");
	ft_bzero(array, (len + 1) * 4);
	free(array);
	return (NULL);
}

void	st_free(t_stacks	*stacks)
{
	int		i;
	t_stack	*temp;
	t_stack	*mem;

	i = 0;
	mem = stacks->a_tail;
	while (i < stacks->a_size + 1)
	{
		temp = mem->next;
		free(mem);
		mem = temp;
		i++;
	}
	free(stacks);
}

void	free_struct(t_stack *mem, int i, int *array)
{
	int		j;
	t_stack	*temp;

	j = 0;
	while (j < i)
	{
		temp = mem->next;
		free(mem);
		mem = temp;
		j++;
	}
	free(array);
}
