/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/01 16:35:31 by lbaumann         ###   ########.fr       */
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
void	print_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

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
void	insertion_sort(t_stack *a);

int		is_sorted(t_stack *a);

//radix sort
void	normalize(t_stack *a, t_frame *head);
void	radix_sort(t_stack *a, t_stack *b);

//chunk sort
int			get_index(t_stack *stack, int value);
t_frame	*	get_nframe(t_stack *stack, int n);
void		create_chunks(t_stack *a, t_stack *b, int nchunks);
void		sort_leftover(t_stack *a, t_stack *b);
int			idx_bestmove(t_stack *a, int limit);
int	get_index_from_indexs(t_stack *stack, int index_s);
void	sort_rest(t_stack *a, t_stack *b);

#endif
