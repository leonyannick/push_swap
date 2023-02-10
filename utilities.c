/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:45:14 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/10 11:17:07 by lbaumann         ###   ########.fr       */
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

void	clear_stack(t_stack *stack)
{
	while (stack->size)
		pop(stack);
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

void	print_stack(t_stack *stack)
{
	t_frame	*temp;
	int		temp_stack_size;

	temp_stack_size = stack->size;
	temp = stack->head;
	while (temp_stack_size)
	{
		/* printf("prev: %i, ", temp->prev->value);
		printf("val: \033[1;31m%i\033[0m ", temp->value);
		printf("next: %i -> , ", temp->next->value); */
		printf("\033[1;31m%i\033[0m (%i) -> ", temp->value, temp->pos);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("\n");
}

void	print_stacks(t_stack *a, t_stack *b, int asize, int bsize)
{
	t_frame	*temp_a;
	t_frame	*temp_b;

	temp_a = a->head;
	temp_b = b->head;
	printf("A \t s(A) \t B \t s(B) \t p(B) \t d(B) \t c(B)\n");
	while (asize || bsize)
	{
		if (asize)
		{
			printf("%i \t %i \t ", temp_a->value, temp_a->index_s);
			temp_a = temp_a->next;
			asize--;
		}
		else
			printf("- \t - \t ");
		if (bsize)
		{
			printf("%i \t %i \t %i \t %i \t %i \t\n", temp_b->value, temp_b->index_s, temp_b->pos, temp_b->dest, temp_b->cost);
			temp_b = temp_b->next;
			bsize--;
		}
		else
			printf("- \t - \t - \t - \t -\n");
		
	}
	printf("\n");
}

