/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:57 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/30 12:10:42 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
-swaps the first 2 elements of the specified stack
-swap only happens if stack contains at least 2 frames
*/
void	swap(t_stack *stack)
{
	t_frame		*first_elem;
	t_frame		*second_elem;

	if (stack->size > 1)
	{
		first_elem = pop(stack);
		second_elem = pop(stack);
		push(stack, first_elem);
		push(stack, second_elem);
	}
}

/*
-pops first element of stack y and pushes it to stack x
-only executed when y has at least one element
*/
void	push_y_to_x(t_stack *x, t_stack *y)
{
	t_frame *frame;

	if (y->size > 0)
	{
		frame = pop(y);
		push(x, frame);
	}
}

/*
-normal (reverse == 0): first element becomes last
-reverse (reverse == 1): last elemebt becomes first
*/
void	rotate(t_stack *stack, int reverse)
{
	if (reverse)
		stack->head = stack->head->prev;
	else
		stack->head = stack->head->next;
}

void sa(t_stack *a)
{
	ft_printf("sa\n");
	swap(a);
}

void sb(t_stack *b)
{
	ft_printf("sb\n");
	swap(b);
}

void ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}

void pa(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	push_y_to_x(a, b);
}

void pb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	push_y_to_x(b, a);
}

void ra(t_stack *a)
{
	ft_printf("ra\n");
	rotate(a, NORMAL);
}

void rb(t_stack *b)
{
	ft_printf("rb\n");
	rotate(b, NORMAL);
}

void rrb(t_stack *b)
{
	ft_printf("rrb\n");
	rotate(b, REVERSE);
}

void rra(t_stack *a)
{
	ft_printf("rra\n");
	rotate(a, REVERSE);
}

void rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rotate(a, REVERSE);
	rotate(b, REVERSE);
}

void rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate(a, NORMAL);
	rotate(b, NORMAL);
}
