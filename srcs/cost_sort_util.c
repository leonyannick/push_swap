/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_sort_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:00:35 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/13 12:42:02 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	abs_val(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

t_frame	*next_smallest(t_stack *stack, int stacksize, t_frame *frame)
{
	t_frame	*temp;
	t_frame	*smallest;

	temp = stack->head;
	smallest = 0;
	while (stacksize)
	{
		if (temp->index_s > frame->index_s && !smallest)
			smallest = temp;
		if (smallest && temp->index_s > frame->index_s
			&& temp->index_s < smallest->index_s)
			smallest = temp;
		temp = temp->next;
		stacksize--;
	}
	return (smallest);
}

t_frame	*next_biggest(t_stack *stack, int stacksize, t_frame *frame)
{
	t_frame	*temp;
	t_frame	*biggest;

	temp = stack->head;
	biggest = 0;
	while (stacksize)
	{
		if (temp->index_s < frame->index_s && !biggest)
			biggest = temp;
		if (biggest && temp->index_s < frame->index_s
			&& temp->index_s > biggest->index_s)
			biggest = temp;
		temp = temp->next;
		stacksize--;
	}
	return (biggest);
}

t_frame	*get_frame_mincost(t_stack *b, int bsize)
{
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
	return (min);
}

t_frame	*determine_rotation(t_frame *min, t_stack *a, t_stack *b)
{
	if (min->pos < 0 && min->dest < 0)
		return (rrr(a, b), min->pos++, min->dest++, min);
	else if (min->pos > 0 && min->dest > 0)
		return (rr(a, b), min->pos--, min->dest--, min);
	else if (min->pos > 0)
		return (rb(b), min->pos--, min);
	else if (min->pos < 0)
		return (rrb(b), min->pos++, min);
	else if (min->dest > 0)
		return (ra(a), min->dest--, min);
	else if (min->dest < 0)
		return (rra(a), min->dest++, min);
	return (NULL);
}
