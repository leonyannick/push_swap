/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/14 12:24:50 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../srcs/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_frame
{
	int				value;
	int				index_s;
	int				pos;
	int				dest;
	int				cost;
	struct s_frame	*next;
	struct s_frame	*prev;
}t_frame;

typedef struct s_stack
{
	t_frame		*head;
	int			size;
}t_stack;

# define REVERSE 1
# define NORMAL 0

//basic stack operations
void		push(t_stack *stack, t_frame *frame);
t_frame		*pop(t_stack *stack);
void		swap(t_stack *stack);
void		push_y_to_x(t_stack *x, t_stack *y);
void		rotate(t_stack *stack, int reverse);

//specific stack operations
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rrb(t_stack *b);
void		rra(t_stack *a);
void		rrr(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);

//insertion sort
void		insertion_sort(t_stack *a, int i, int j, int cnt);

//radix sort
void		radix_sort(t_stack *a, t_stack *b);

//create chunks
void		create_chunks(t_stack *a, t_stack *b, int chunksz);
int			idx_bestmove(t_stack *a, int limit);
void		n_rotate(t_stack *stack, int n, int reverse);

//cost sort
void		determine_pos(t_stack *b);
void		determine_dest(t_stack *a, t_stack *b, int asize, int bsize);
void		calculate_costs(t_stack *b, int bsize);
t_frame		*get_frame_mincost(t_stack *b, int bsize);
void		cost_sort(t_stack *a, t_stack *b);

//cost sort util
int			abs_val(int nb);
void		rotate_to_start(t_stack *a);
t_frame		*next_smallest(t_stack *stack, int stacksize, t_frame *frame);
t_frame		*next_biggest(t_stack *stack, int stacksize, t_frame *frame);
t_frame		*determine_rotation(t_frame *min, t_stack *a, t_stack *b);

//utilities
int			get_index(t_stack *stack, int value);
t_frame		*get_nframe(t_stack *stack, int n);
int			copy_stack(t_stack *src, int src_size, t_stack **destination);
void		free_mem(t_stack *a, t_stack *b);
void		assign_index(t_stack *stack, int stack_size);
void		clear_stack(t_stack *stack);
void		sort_3(t_stack *a);
int			is_sorted(t_stack *a);
//void		print_stack(t_stack *stack);
//void		print_stacks(t_stack *a, t_stack *b, int asize, int bsize);

//input
int			initialize_stacks(t_stack **a, t_stack **b);
int			check_input(int arg_idx, char **args, t_stack *a);
int			is_duplicate(t_stack *stack, int num);

#endif
