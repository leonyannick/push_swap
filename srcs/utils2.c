/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:34:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 09:41:21 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_index(t_stack *stack, int value)
{
	t_frame	*frame;
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

void	sort_3(t_stack *a)
{
	int	head_val;
	int	next_val;
	int	prev_val;

	head_val = a->head->value;
	next_val = a->head->next->value;
	prev_val = a->head->prev->value;
	if (is_sorted(a))
		return ;
	else if (head_val < next_val && head_val < prev_val && prev_val < next_val)
	{
		sa(a);
		ra(a);
	}
	else if (head_val > next_val && head_val > prev_val && prev_val > next_val)
		ra(a);
	else if (head_val > next_val && head_val > prev_val && prev_val < next_val)
	{
		sa(a);
		rra(a);
	}
	else if (head_val > next_val && head_val < prev_val)
		sa(a);
	else
		rra(a);
}

int	is_sorted(t_stack *a)
{
	int			nvals;
	int			ncompares;
	t_frame		*head;
	t_frame		*val;

	head = a->head;
	nvals = (a->size - 1);
	while (nvals)
	{
		ncompares = nvals;
		val = head;
		while (ncompares)
		{
			if ((val->value) > (val->next->value))
				return (0);
			val = val->next;
			ncompares--;
		}
		val = head->next;
		head = head->next;
		nvals--;
	}
	return (1);
}

/* #include <stdio.h>
void	print_stacks(t_stack *a, t_stack *b, int asize, int bsize)
{
	t_frame	*temp_a;
	t_frame	*temp_b;

	temp_a = a->head;
	temp_b = b->head;
	printf("A \t p(A) \t B \t p(B) \t d(B) \t c(B)\n");
	while (asize || bsize)
	{
		if (asize)
		{
			printf("%i \t %i \t ", temp_a->value, temp_a->pos);
			temp_a = temp_a->next;
			asize--;
		}
		else
			printf("- \t - \t ");
		if (bsize)
		{
			printf("%i \t %i \t %i \t %i \t\n", temp_b->value, temp_b->pos,
				temp_b->dest, temp_b->cost);
			temp_b = temp_b->next;
			bsize--;
		}
		else
			printf("- \t - \t - \t -\n");
		
	}
	printf("\n");
} */

/* void	print_stack(t_stack *stack)
{
	t_frame	*temp;
	int		temp_stack_size;

	temp_stack_size = stack->size;
	temp = stack->head;
	while (temp_stack_size)
	{
		printf("\033[1;31m%i\033[0m (%i) -> ", temp->value, temp->pos);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("\n");
} */
