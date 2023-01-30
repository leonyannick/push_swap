/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/30 09:48:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void normalize(t_stack *a, t_frame *head)
{
	int			nvals;
	int			ncompares;
	int			is_biggest;
	t_frame 	*temp;
	t_frame		*val;

	head = a->head;
	nvals = a->size - 1;
	val = head;
	while (nvals > -1)
	{
		is_biggest = 1;
		ncompares = (a->size - 1);
		temp = val;
		while (ncompares)
		{
			if ((temp->value < (val->next->value) && val->next->index == -1))
				is_biggest = 0;
			val = val->next;
			ncompares--;
		}
		if (is_biggest && temp->index == -1)
		{
			temp->index = nvals;
			nvals--;
		}
		val = head->next;
		head = head->next;
	}
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

