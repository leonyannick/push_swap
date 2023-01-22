/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/20 15:18:10 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*a;
	t_stack	*popped_node;

	//push should just return and not crash, when NULL is passes as head
	push(NULL, 1);

	//push should be able to add to empty stack (initialized as NULL)
	a = NULL;
	push(&a, 5);
	push(&a, 1);
	push(&a, 3);
	print_stack(a);
	
	//popped node can be saved
	popped_node = pop(&a);
	printf("stack without 3:\n");
	print_stack(a);
	printf("popped node, aka 3:\n");
	print_stack(popped_node);

	//null should be returned by pop in case of empty stack
	a = NULL;
	if (pop(&a) == NULL)
		printf("NULL return because of empty stack\n");
	
}
