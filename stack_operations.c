/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/22 21:19:29 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
void	push(t_stack *stack, int value)
{
	t_frame		*frame;
	
	frame = malloc(sizeof(t_frame));
	if (!frame)
		return ;
	frame->value = value;
	frame->next = stack->head;
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
	t_frame	*popped_frame;

	if (!stack->head)
		return (NULL);
	popped_frame = stack->head;
	stack->head = stack->head->next;
	popped_frame->next = NULL;
	(stack->size)--;
	return (popped_frame);
}

void	print_stack(t_stack *stack)
{
	while (stack->head)
	{
		printf("%i\n", stack->head->value);
		printf("stack size: %i\n", stack->size);
		stack->head = stack->head->next;
	}
}

int	main(void)
{
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->size = 0;
	t_frame	*temp;


	push(a, 5);
	push(a, 1);
	push(a, 3);
	temp = pop(a);
	printf("temp.value: %i\n", temp->value);
	print_stack(a);
}
