/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_stack_ops.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/14 12:22:55 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
	DESCRIPTION:
		-allocates memory for new node and pushes it to front of stack
		-if new node ist pushed on empty stack, node->next is set to NULL
		-if allocation fails the function returns immeditely
	PARAMETERS:
		-head: address of head of respective stack
		-value: integer to be pushed to the stack
	RETURN:
		-no return value -> maybe has to be added later in case whole stack
		needs to be free after allocation fails
*/
void	push(t_stack *stack, t_frame *frame)
{
	t_frame		*tail;

	if (!stack || !frame)
		return ;
	if (stack->size > 0)
	{
		tail = stack->head->prev;
		frame->next = stack->head;
		frame->prev = tail;
		stack->head->prev = frame;
		tail->next = frame;
	}
	else
	{
		frame->next = frame;
		frame->prev = frame;
	}
	stack->head = frame;
	(stack->size)++;
}

/*
	DESCRIPTION:
		pops first element of the stack and returns popped node
	PARAMETERS:
		head: address of head of respective stack
	RETURN:
		-returns pointer to popped node, so it can be saved/freed
		-NULL in case the stack is empty and there is no element
		to be popped
*/
t_frame	*pop(t_stack *stack)
{
	t_frame		*popped_frame;

	if (!stack->head)
		return (0);
	popped_frame = stack->head;
	if (stack->size != 1)
	{
		stack->head = stack->head->next;
		stack->head->prev = popped_frame->prev;
		popped_frame->prev->next = stack->head;
	}
	(stack->size)--;
	return (popped_frame);
}

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
	t_frame	*frame;

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
	if (stack->size)
	{
		if (reverse)
			stack->head = stack->head->prev;
		else
			stack->head = stack->head->next;
	}
}
