/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 15:44:36 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/30 19:10:06 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include	<stdlib.h>
# include	<unistd.h>
# include	<fcntl.h>
# include <stdbool.h>
# include "../PRINT/ft_printf.h"
# include "../LIB/libft.h"
# include "../GNL/get_next_line.h"

//data structs

typedef struct s_stack
{
	struct s_stack	*previous;
	struct s_stack	*next;
	int				num;
}	t_stack;

typedef struct s_stacks
{
	t_stack		*temp_head;
	t_stack		*temp_b_head;
	int			b_size;
	int			a_size;
	t_stack		*a_tail;
	t_stack		*b_tail;
}	t_stacks;

// moves func' s
void		sa(t_stacks *stacks, int sig);
void		sb(t_stacks *stacks, int sig);
void		ss(t_stacks *stacks, int sig);
void		pb(t_stacks *stacks, int sig);
void		pa(t_stacks *stacks, int sig);
void		ra(t_stacks *stacks, int mode);
void		rb(t_stacks *stacks, int mode);
void		rr(t_stacks *stacks, int sig);
void		rra(t_stacks *stacks, int mode);
void		rrb(t_stacks *stacks, int mode);
void		rrr(t_stacks *stacks, int sig);

// moves helpers
t_stack		*init_push(t_stack *node);
t_stack		*delete_node(t_stack *tail, int size);
void		add_node(t_stack *tail, int size, t_stack *node);
void		swap(int *a, int *b);
t_stack		*forward_increment(t_stack *node, int times);

//  mandatory func's
t_stacks	*init_stacks(t_stack *stack_a, int size, int *array);
int			check_vals(char **av);
int			*get_vals(char **av, int len);
t_stack		*convert_array(char **av, int *array);
int			twd_len(char **args);
void		d_free(char	**args);
int			*arr_panic(int *array, int len, int mode);
t_stack		*panic(t_stack *mem, int *array);
void		free_struct(t_stack	*mem, int i, int *array);
void		st_free(t_stacks	*stacks);
int			this_move(char	*move, t_stacks	*stacks);
int			st_is_sorted(t_stacks	*stacks);
void		quicksort(int *arr, int low, int high);

#endif
