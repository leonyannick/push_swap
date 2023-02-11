/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/10 17:51:24 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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
	if (is_sorted(a))
		return (0);
	assign_index(a, a->size);
	if (a->size == 3)
		sort_3(a);
	else
	{
		int nchunks = 2;
		int chunksz = (a->size - 3) / nchunks;
		create_chunks(a, b, nchunks, chunksz);
		sort_3(a);
		t_frame *min;
		while (b->size)
		{
			
			determine_pos(b);
			determine_dest(a, b, a->size, b->size);
			calculate_costs(b, b->size);
			min = get_frame_mincost(b, b->size);
			print_stacks(a, b, a->size, b->size);
			while (min->pos > 0 && min->dest > 0)
			{
				rr(a, b);
				min->pos--;
				min->dest--;
			}
			while (min->pos < 0 && min->dest < 0)
			{
				rrr(a, b);
				min->pos++;
				min->dest++;
			}
			while (min->pos > 0)
			{
				rb(b);
				min->pos--;
			}
			while (min->dest > 0)
			{
				ra(a);
				min->dest--;
			}
			while (min->pos < 0)
			{
				rrb(b);
				min->pos++;
			}
			while (min->dest < 0)
			{
				rra(b);
				min->dest++;
			}
			pa(a, b);
		}



		print_stacks(a, b, a->size, b->size);
		
		
	}
}
