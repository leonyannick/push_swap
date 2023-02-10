/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/08 15:45:54 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
		printf("\033[1;31m%i\033[0m (%i) -> ", temp->value, temp->index_s);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("\n");
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

void	sort_small(t_stack *a, t_stack *b)
{
	int		curr_idx;
	int		a_size;
	
	curr_idx = 0;
	a_size = a->size;
	while (curr_idx < (a_size - 3))
	{
		if (a->head->index_s == curr_idx)
		{
			pb(a, b);
			curr_idx++;
		}
		else
			ra(a);
	}
	sort_3(a);
	while (curr_idx)
	{
		pa(a, b);
		curr_idx--;
	}
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	
	argv++;
	argc -= 2;
	if (!initialize_stacks(&a, &b) || !check_input(argc, argv, a))
	{
		free_mem(a, b);
		return (write(2, "Error\n", 6), 0);
	}
	assign_index(a, a->size);
	if (is_sorted(a))
		return (0);
	
	/* print_stack(a);
	if (is_sorted(a))
	{
		printf("sorted\n");
		return (0);
	}
	if (a->size == 3)
		sort_3(a); */
	//print_stack(a);
	//normalize(a, a->head);
	//print_stack(a);
	//insertion_sort(a);
	// normalize(a, a->head);
	// sort_small(a, b);
	// int nchunks = 4;
	// int chunksz = a->size / nchunks;
	// normalize(a, a->head);
	// print_stack(a);
	// radix_sort(a, b);
	//create_chunks(a, b, nchunks, chunksz);
	//print_stack(a);
	//print_stack(b);
	//sort_leftover(a, b);
	//print_stack(b);
	//sort_rest(a, b);
}
