/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:12:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/20 15:17:51 by lbaumann         ###   ########.fr       */
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
void	push(t_stack **head, int value)
{
	t_stack		*node;
	
	if (!head)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	if (*head)
		node->next = *head;
	else
		node->next = NULL;
	*head = node;
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
t_stack	*pop(t_stack **head)
{
	t_stack	*popped_node;

	if (!head || !*head)
		return (NULL);
	if((*head)->next)
	{
		popped_node = *head;
		*head = (*head)->next;
		popped_node->next = NULL;
		return (popped_node);
	}
	return (NULL);
}

void	print_stack(t_stack *head)
{
	while (head)
	{
		printf("%i\n", head->value);
		head = head->next;
	}
}

/* int	main(void)
{
	t_stack	*a = NULL;
	pop(&a);
	// t_stack *b;

	// push(&a, 5);
	// push(&a, 1);
	// push(&a, 3);
	// b = pop(&a);
	// print_stack(a);
	// printf("\n");
	// print_stack(b);
	
	
} */
