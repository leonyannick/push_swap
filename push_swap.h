/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/30 09:49:34 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_frame
{
	int				value;
	int				index;
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
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
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
void normalize(t_stack *a, t_frame *head);

#endif
