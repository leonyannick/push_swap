/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:45:14 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/08 15:31:50 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, int value)
{
	t_frame *frame;
	int		index;
	
	frame = stack->head;
	index = 0;
	while (index < (stack->size - 1) && frame->value != value)
	{
		frame = frame->next;
		index++;
	}
	return (index);
}

t_frame *get_nframe(t_stack *stack, int n)
{
	int		i;
	t_frame	*head;

	i = 0;
	head = stack->head;
	while (i < n)
	{
		head = head->next;
		i++;
	}
	return(head);
}

/* void normalize(t_stack *a, t_frame *head)
{
	int			nvals;
	int			ncompares;
	int			is_biggest;
	t_frame		*temp;
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
			if ((temp->value < (val->next->value) && val->next->index_s == -1))
				is_biggest = 0;
			val = val->next;
			ncompares--;
		}
		if (is_biggest && temp->index_s == -1)
		{
			temp->index_s = nvals;
			nvals--;
		}
		val = head->next;
		head = head->next;
	}
} */

void	free_mem(t_stack *a, t_stack *b)
{
	if (a)
	{
		clear_stack(a);
		free(a);
	}
	if (b)
	{
		clear_stack(b);
		free(b);
	}
}

void	assign_index(t_stack *stack, int stack_size)
{
	t_stack	*a_sorted;
	t_frame *frame;

	copy_stack(stack, stack_size, &a_sorted);
	insertion_sort(a_sorted);
	frame = stack->head;
	while (stack_size)
	{
		frame->index_s = get_index(a_sorted, frame->value);
		frame = frame->next;
		stack_size--;
	}
	free_mem(a_sorted, NULL);
}

int	copy_stack(t_stack *src, int src_size, t_stack **destination)
{
	t_frame	*new;
	t_frame	*src_frame;

	*destination = malloc(sizeof(t_stack));
	if (!*destination)
		return (0);
	(*destination)->size = 0;
	src_frame = src->head->prev;
	while (src_size)
	{
		new = malloc(sizeof(t_frame));
		if (!new)
		{
			free_mem(*destination, NULL);
			return (0);
		}
		new->value = src_frame->value;
		push(*destination, new);
		src_frame = src_frame->prev;
		src_size--;
	}
	return (1);
}

