/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:50:13 by ozahir            #+#    #+#             */
/*   Updated: 2022/05/26 21:08:42 by ozahir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
	int				index;
	bool			out;
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

void		dra(t_stacks *stacks, int times);
void		drra(t_stacks *stacks, int times);
void		drb(t_stacks *stacks, int times);
void		drrb(t_stacks *stacks, int times);

// moves helpers
t_stack		*init_push(t_stack *node);
t_stack		*delete_node(t_stack *tail, int size);
void		add_node(t_stack *tail, int size, t_stack *node);
void		swap(int *a, int *b);
t_stack		*forward_increment(t_stack *node, int times);

//  mandatory func's
t_stacks	*init_stacks(t_stack *stack_a, int size, int *array);
void		quicksort(int *arr, int low, int high);
int			bool_count(t_stack *stack, int times);
void		flush_bools(t_stacks *stacks);
int			check_vals(char **av);
int			*get_vals(char **av, int len);
void		indexing_func(t_stack *stack_a, int *array, int len);
t_stack		*convert_array(char **av, int *array);
int			twd_len(char **args);
void		d_free(char	**args);
int			*arr_panic(int *array, int len, int mode);
t_stack		*panic(t_stack *mem, int *array);
int			flag_to_out(t_stacks *stacks, int *array, int total);
int			flaged_to_b(t_stacks *stacks, int *array, int piv);
void		reverse_push(t_stacks *stacks);
void		push_smallest(t_stacks *stacks);
void		push_swap(t_stacks *stacks, int *array);
void		five_sort(t_stacks *stacks);
void		three_sort(t_stacks *stack);
void		rotate_b(t_stacks *stacks, int index);
void		rotate_a(t_stacks *stacks, int i);
void		free_struct(t_stack	*mem, int i, int *array);
void		st_free(t_stacks *stacks);
void		rotate_rr(t_stacks *stacks, int mode);

#endif
