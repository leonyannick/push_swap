/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:45:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/23 15:32:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	int	popped_value;

	a = malloc(sizeof(t_stack));
	a->head = NULL;
	a->size = 0;
	//push should just return and not crash, when NULL is passes as head
	push(NULL, 1);
	
	//push should be able to add to empty stack (initialized as NULL)
	a->head = NULL;
	push(a, 5);
	push(a, 1);
	push(a, 3);
	print_stack(a);
	
	//popped node can be saved
	popped_value = pop(a);
	printf("stack without 3:\n");
	print_stack(a);
	printf("popped node, aka 3:\n");
	printf("temp.value: %i\n", popped_value);

	//null should be returned by pop in case of empty stack
	/* a->head = NULL;
	if (pop(a) == NULL)
		printf("NULL return because of empty stack\n");
	 */
}
