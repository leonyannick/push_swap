/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_chunks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:19:30 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/15 09:35:15 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	idx_bestmove(t_stack *a, int limit)
{
	int		radius;
	t_frame	*nframe;

	if (a->head->index_s < limit)
		return (0);
	radius = 1;
	while (radius <= (((a->size - 1) / 2) + 1))
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

void	create_chunks(t_stack *a, t_stack *b, int chunksz)
{
	int		limit;
	int		idx;
	int		i;

	limit = 0;
	i = 0;
	while (a->size > 3)
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

void	two_chunks(t_stack *a, t_stack *b)
{
	int		asize;

	asize = a->size;
	while (b->size < (asize / 2))
	{
		if (a->head->index_s < (asize / 2))
			pb(a, b);
		else
			ra(a);
	}
	while (a->size > 3)
	{
		pb(a, b);
	}
}
