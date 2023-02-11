/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:59:02 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/11 17:03:28 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
assigns a value to the pos attribute of each frame in b. the value states how
many rotations are needed to bring this element to the top. a negative value
indicates reverse rotations
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
assigns the cost attribute. 
*/
void	determine_dest(t_stack *a, t_stack *b, int asize, int bsize)
{
	t_frame	*temp;
	t_frame	*a_frame;
	t_frame	*b_frame;

	b_frame = b->head;
	while (bsize)
	{
		asize = a->size;
		temp = next_smallest(a, a->size, b_frame);
		if (temp)
			b_frame->dest = temp->pos;
		else
		{
			temp = next_biggest(a, a->size, b_frame);
			b_frame->dest = temp->pos + 1;
		}
		b_frame = b_frame->next;
		bsize--;
	}
}

void	calculate_costs(t_stack *b, int bsize)
{
	t_frame	*bframe;

	bframe = b->head;
	while (bsize)
	{
		bframe->cost = abs(bframe->dest) + abs(bframe->pos);
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
