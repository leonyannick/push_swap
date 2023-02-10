/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/10 12:18:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
#include <stdio.h>

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
void	push(t_stack *stack, t_frame *frame);
t_frame	*pop(t_stack *stack);

//more specific stack operations
void	swap(t_stack *stack);
void	push_y_to_x(t_stack *x, t_stack *y);
void	rotate(t_stack *stack, int reverse);

//really specific stack operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rrb(t_stack *b);
void	rra(t_stack *a);
void	rrr(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);

//insertion algorithms
void		insertion_sort(t_stack *a);

void		sort_3(t_stack *a);

//radix sort
void		radix_sort(t_stack *a, t_stack *b);

//chunk sort
void		create_chunks(t_stack *a, t_stack *b, int nchunks, int chunksz);
void		sort_leftover(t_stack *a, t_stack *b);
int			idx_bestmove(t_stack *a, int limit);
int			get_index_from_indexs(t_stack *stack, int index_s);
void		sort_rest(t_stack *a, t_stack *b);

//cost sort
void	determine_pos(t_stack *b);
void	determine_dest(t_stack *a, t_stack *b, int asize, int bsize);
void	calculate_costs(t_stack *b, int bsize);
t_frame *get_frame_mincost(t_stack *b, int bsize);

//utilities
int			get_index(t_stack *stack, int value);
t_frame	*	get_nframe(t_stack *stack, int n);
int			copy_stack(t_stack *src, int src_size, t_stack **destination);
void		free_mem(t_stack *a, t_stack *b);
void		assign_index(t_stack *stack, int stack_size);
void		print_stack(t_stack *stack);
void		clear_stack(t_stack *stack);
void	print_stacks(t_stack *a, t_stack *b, int asize, int bsize);

//input
int			initialize_stacks(t_stack **a, t_stack **b);
int			is_sorted(t_stack *a);
int			check_input(int arg_idx, char **nums, t_stack *a);
int			is_duplicate(t_stack *stack, int num);

#endif
