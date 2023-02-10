/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:43:08 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/08 15:18:03 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_from_indexs(t_stack *stack, int index_s)
{
	t_frame *frame;
	int		index;
	
	frame = stack->head;
	index = 0;
	while (index < (stack->size - 1) && frame->index_s != index_s)
	{
		frame = frame->next;
		index++;
	}
	return (index);
}

int	get_index_from_indexs_range(t_stack *stack, int index_s)
{
	t_frame *frame;
	int		index;
	
	frame = stack->head;
	index = 0;
	while ((index < (stack->size - 1) && frame->index_s != index_s) && (index < (stack->size - 1) && frame->index_s != index_s - 1)) // && (index < (stack->size - 2) && frame->index_s != index_s - 2))
	{
		frame = frame->next;
		index++;
	}
	return (index);
}

void	n_rotate(t_stack *stack, int n, int reverse)
{
	while (n)
	{
		if (reverse)
			rra(stack);
		else
			ra(stack);
		n--;
	}
}

void	n_rotateb(t_stack *stack, int n, int reverse)
{
	while (n)
	{
		if (reverse)
			rrb(stack);
		else
			rb(stack);
		n--;
	}
}


int	idx_bestmove(t_stack *a, int limit)
{
	int	radius;
	t_frame *nframe;

	if (a->head->index_s < limit)
		return (0);
	radius = 1;
	while(radius <= (((a->size - 1) / 2) + 1))
	{
		nframe = get_nframe(a, radius);
		if (nframe->index_s < limit)
			return (radius);
		nframe = get_nframe(a, (a->size - radius));
		if (nframe->index_s < limit)
			return (a->size - radius);
		radius++;
	}
	return (0);
}

int	idx_bestmove_range(t_stack *stack, int limit)
{
	int	radius;
	t_frame *nframe;

	if (stack->head->index_s == limit || stack->head->index_s == (limit - 1) || stack->head->index_s == (limit - 2))
		return (0);
	radius = 1;
	while(radius <= (((stack->size - 1) / 2) + 1))
	{
		nframe = get_nframe(stack, radius);
		if (nframe->index_s == limit || nframe->index_s == (limit - 1) || nframe->index_s == (limit - 2))
			return (radius);
		nframe = get_nframe(stack, (stack->size - radius));
		if (nframe->index_s == limit || nframe->index_s == (limit - 1) || nframe->index_s == (limit - 2))
			return (stack->size - radius);
		radius++;
	}
	return (0);
}

void	create_chunks(t_stack *a, t_stack *b, int nchunks, int chunksz)
{
	int		limit;
	int		idx;
	int		i;

	limit = 0;
	i = 0;
	while (b->size < chunksz * (nchunks - 1))
	{
		if (i % chunksz == 0)
			limit += chunksz;
		idx = idx_bestmove(a, limit);
		if (idx < (a->size / 2))
			n_rotate(a, idx, NORMAL);
		else
			n_rotate(a, a->size - idx, REVERSE);
		pb(a, b);
		i++;
	}
}

void sort_leftover(t_stack *a, t_stack *b)
{
	int	i;
	int	idx;
	int n;
	int	pair;

	i = 0;
	n = b->size + 1;
	while (a->size > 1)
	{
		pair = 2;
		while (pair)
		{
			idx = idx_bestmove_range(a, n);
			if (idx < (a->size / 2))
				n_rotate(a, idx, NORMAL);
			else
				n_rotate(a, a->size - idx, REVERSE);
			pb(a, b);
			pair--;
		}
		n += 2;
		i += 2;
		if (b->head->value < b->head->next->value)
			sb(b);
	}
	while (i)
	{
		pa(a, b);
		i--;
	}
}

/* void	sort_rest(t_stack *a, t_stack *b)
{
	int	limit;
	int	idx;
	
	limit = b->size - 1;
	while (b->size)
	{
		idx = get_index_from_indexs(b, limit);
		if (idx < (b->size / 2))
			n_rotateb(b, idx, NORMAL);
		else
			n_rotateb(b, b->size - idx, REVERSE);
		pa(a, b);
		limit--;
	}
} */

void	reorder_3(t_stack *a, t_stack *b)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (is_sorted(a)) //123
		return ;
	else if (first < second && first < third && third < second) //132
	{
		ra(a);
		sa(a);
		rra(a);
	}
	else if (first < second && first > third && third < second) //231
	{
		pb(a, b);
		pb(a, b);
		ra(a);
		pa(a, b);
		pa(a, b);
		rra(a);
		
	}
	else if (first > second && first > third && third < second) //321
	{
		sa(a);
		pb(a, b);
		pb(a, b);
		ra(a);
		pa(a, b);
		pa(a, b);
		rra(a);
	}
	else if (first > second && first < third) //213
		sa(a);
	else //312
	{
		pb(a, b);
		ra(a);
		ra(a);
		pa(a, b);
		rra(a);
		rra(a);
		
	}
}


void	sort_rest(t_stack *a, t_stack *b)
{
	int	limit;
	int	idx;
	int	pair;
	
	limit = b->size - 1;
	while (b->size > 1)
	{
		pair = 2;
		while (pair)
		{
			idx = idx_bestmove_range(b, limit);
			if (idx < (b->size / 2))
				n_rotateb(b, idx, NORMAL);
			else
				n_rotateb(b, b->size - idx, REVERSE);
			pa(a, b);
			pair--;
		}
		limit -= 2;
		if (a->head->value > a->head->next->value)
			sa(a);
	}
	pa(a, b);
}

/* void	sort_rest(t_stack *a, t_stack *b)
{
	int	limit;
	int	idx;
	int	temp;
	int	triple;
	
	limit = b->size - 1;
	while (b->size)
	{
		if (b->size < 3)
		{
			pa(a, b);
			limit--;
			continue;
		}
		triple = 3;
		while (triple)
		{
			idx = idx_bestmove_range(b, limit);
			if (idx < (b->size / 2))
				n_rotateb(b, idx, NORMAL);
			else
				n_rotateb(b, b->size - idx, REVERSE);
			pa(a, b);
			triple--;
		}
		limit -= 3;
		reorder_3(a, b);
	}
} */
