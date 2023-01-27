/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/27 15:59:00 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void normalize(t_stack *stack, int stack_size)
{
	
}


	
/* t_frame	*temp;
int		curr_index;
int		curr_element;

temp = head;
curr_index = 0;
while (curr_index < stack->size) //is executed stack size times
{
	if (temp->index == -1)
	{
		temp->index = curr_index;
		curr_index++;
	}
	else
	{
		temp = temp->next;
		continue;
	}
	curr_element = 0;
	while (curr_element < (stack->size - 1)) //is executed stack size times
	{
		if (temp->value > temp->next->value && temp->next->index == -1)
		{
			temp->index = -1;
			temp = head->next;
			temp->index = curr_index;
		}
		temp = temp->next;
		curr_element++;
	}
	temp = head;
} */

