/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:59:02 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 09:22:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
assigns a value to the pos attribute of each frame in a stack. the value states 
how many rotations are needed to bring this element to the top. a negative 
value indicates reverse rotations (elements in the second half are assigned
negative values)

Example:
stack	pos
6		0
7		1
8		2
9 		-3
10		-2
11		-1
*/
void	determine_pos(t_stack *stack)
{
	int		pos;
	t_frame	*frame;

	frame = stack->head;
	pos = 0;
	while (pos < ((stack->size / 2) + 1))
	{
		frame->pos = pos;
		frame = frame->next;
		pos++;
	}
	pos = -1;
	frame = stack->head->prev;
	while (-pos < ((stack->size / 2) + 1))
	{
		frame->pos = pos;
		frame = frame->prev;
		pos--;
	}
}

/*
determine destination assigns a value to the dest attribute of
each frame in stack b. it indicates how many rotations are 
needed to insert the frame at the correct position in a, 
so that the stack a remains sorted
-next_biggest looks for the next bigger number where the
frame should be inserted
*/
void	determine_dest(t_stack *a, t_stack *b, int asize, int bsize)
{
	t_frame	*temp;
	t_frame	*b_frame;

	b_frame = b->head;
	while (bsize)
	{
		asize = a->size;
		temp = next_biggest(a, a->size, b_frame);
		if (temp)
			b_frame->dest = temp->pos;
		else
		{
			temp = next_smallest(a, a->size, b_frame);
			b_frame->dest = temp->pos + 1;
		}
		b_frame = b_frame->next;
		bsize--;
	}
}

/*
adds pos + dest for total cost (abs val is needed because of 
negative values)
*/
void	calculate_costs(t_stack *b, int bsize)
{
	t_frame	*bframe;

	bframe = b->head;
	while (bsize)
	{
		bframe->cost = abs_val(bframe->dest) + abs_val(bframe->pos);
		bframe = bframe->next;
		bsize--;
	}
}

void	rotate_to_start(t_stack *a)
{
	t_frame	*aframe;

	determine_pos(a);
	aframe = a->head;
	while (aframe->index_s != 0)
		aframe = aframe->next;
	while (aframe->pos > 0)
	{
		ra(a);
		aframe->pos--;
	}
	while (aframe->pos < 0)
	{
		rra(a);
		aframe->pos++;
	}
}

void	cost_sort(t_stack *a, t_stack *b)
{
	t_frame	*min;

	while (b->size)
	{
		determine_pos(b);
		determine_pos(a);
		determine_dest(a, b, a->size, b->size);
		calculate_costs(b, b->size);
		min = get_frame_mincost(b, b->size);
		while (min->pos || min->dest)
			min = determine_rotation(min, a, b);
		pa(a, b);
	}
	rotate_to_start(a);
}
