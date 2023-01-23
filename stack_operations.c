/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:57 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/23 15:15:30 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
-swaps the first 2 elements of the specified stack
-swap only happens if stack contains at least 2 frames
*/
void	swap(t_stack *stack)
{
	int		first_elem;
	int		second_elem;

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
	int	value;

	if (y->size > 0)
	{
		value = pop(y);
		push(x, value);
	}
}

/*
-updates tail to point to new head after rotate operations
*/
void	update_tail(t_stack stack)
{
	
}

/*

*/
void	rotate(t_stack *stack, int reverse)
{
	t_frame *head_temp;
	
	if (reverse)
	{
		head_temp = stack->head;
		stack->head = stack->tail;
		stack->tail = head_temp;
		stack->tail->next = stack->head;
	}
	else
	{
		head_temp = stack->head;
		stack->head = stack->head->next;
		stack->tail = head_temp;
		stack->tail->next = stack->head;
	}
}

#include <stdio.h>

int	main(void)
{
	//tests for swap:
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->size = 0;

	/* //empty stack swap
	a->head = NULL;
	swap(a);
	print_stack(a);

	//one element swap
	push(a, 5);push_y_to_x(a, b);
	print_stack(a);
	swap(a);
	printf("swapped:\n");
	print_stack(a);
	printf("\n");
	
	//normal swap
	push(a, 1);
	push(a, 3);
	print_stack(a);
	swap(a);
	printf("swapped:\n");
	print_stack(a);
	printf("\n"); */

	//tests for push_y_to_x
	/* t_stack	*b;
	b = malloc(sizeof(t_stack));
	b->size = 0;

	//normal swapping
	push(a, 5);
	push(a, 1);
	push(a, 3);
	printf("a before pa:\t");
	print_stack(a);
	push(b, 7);
	push(b, 2);
	push(b, 4);
	printf("b before pa:\t");
	print_stack(b);
	push_y_to_x(a, b);
	printf("a after pa:\t");
	print_stack(a);
	printf("b after pa:\t");
	print_stack(b);
	printf("\n");

	//empty stack y
	clear_stack(b);
	printf("a before pa:\t");
	print_stack(a);
	printf("b before pa:\t");
	print_stack(b);
	push_y_to_x(a, b);
	printf("a after pa:\t");
	print_stack(a);
	printf("b after pa:\t");
	print_stack(b); */

	//tests for rotate
	push(a, 5);
	push(a, 1);
	push(a, 3);
	push(a, 7);
	push(a, 9);
	printf("a before rotate:\t");
	print_stack(a);
	rotate(a, REVERSE);
	print_stack(a);
	rotate(a, NORMAL);
	printf("a after rotate:\t");
	print_stack(a);
	

}
