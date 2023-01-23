/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/23 12:07:45 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
	
	if (!stack)
		return ;
	frame = malloc(sizeof(t_frame));
	if (!frame)
		return ;
	if (stack->size == 0)
		stack->tail = frame;
	else
		stack->tail->next = frame;
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
int	pop(t_stack *stack)
{
	int			popped_value;
	t_frame		*popped_frame;
	
	if (!stack->head)
		return (0);
	popped_value = stack->head->value;
	popped_frame = stack->head;
	stack->head = stack->head->next;
	free(popped_frame);
	(stack->size)--;
	return (popped_value);
}

void	print_stack(t_stack *stack)
{
	t_frame	*temp;
	int		temp_stack_size;

	temp_stack_size = stack->size;
	temp = stack->head;
	while (temp_stack_size)
	{
		//printf("%p, ", temp);
		printf("%i -> ", temp->value);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("%p", temp);
	printf("\n");
}

void	clear_stack(t_stack *stack)
{
	while (stack->size)
		pop(stack);
}

/* int	main(void)
{
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->size = 0;
	t_frame	*temp;


	push(a, 5);
	push(a, 1);
	push(a, 3);
	print_stack(a);
	temp = pop(a);
	printf("temp.value: %i\n", temp->value);
	print_stack(a);
} */
