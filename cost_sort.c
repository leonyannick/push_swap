/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:59:02 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/10 13:22:31 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
}

/*
assigns a value to the pos attribute of each frame in b. the value states how
many rotations are needed to bring this element to the top. a negative value
indicates reverse rotations
*/
void	determine_pos(t_stack *b)
{
	int	pos;
	t_frame	*frame;
	
	frame = b->head;
	pos = 0;
	while (pos < ((b->size / 2) + 1))
	{
		frame->pos = pos;
		frame = frame->next;
		pos++;
	}
	pos = -1;
	frame = b->head->prev;
	while (-pos < ((b->size / 2) + 1))
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
	int	dest;
	t_frame	*a_frame;
	t_frame	*b_frame;
	b_frame = b->head;
	while (bsize)
	{
		dest = 0;
		asize = a->size;
		a_frame = a->head;
		while (asize)
		{
			if (b_frame->index_s > a_frame->index_s)
				dest++;
			a_frame = a_frame->next;
			asize--;
		}
		if (dest >= (a->size / 2))
			dest = dest - a->size;
		b_frame->dest = dest;
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

t_frame *get_frame_mincost(t_stack *b, int bsize)
{
	int		i;
	t_frame	*bframe;
	t_frame	*min;

	bframe = b->head;
	min = bframe;
	while (bsize)
	{
		if (min->cost > bframe->cost)
			min = bframe;
		bframe = bframe->next;
		bsize--;
	}
	return(min);
}
