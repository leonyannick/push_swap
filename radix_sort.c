/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/30 13:34:15 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void normalize(t_stack *a, t_frame *head)
{
	int			nvals;
	int			ncompares;
	int			is_biggest;
	t_frame 	*temp;
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
			if ((temp->value < (val->next->value) && val->next->index == -1))
				is_biggest = 0;
			val = val->next;
			ncompares--;
		}
		if (is_biggest && temp->index == -1)
		{
			temp->index = nvals;
			nvals--;
		}
		val = head->next;
		head = head->next;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bin_digits;
	int	i;
	int a_size;
	int b_size;

	bin_digits = 1;
	i = 0;
	while ((a->size - 1) >> bin_digits)
		bin_digits++;
	while(i < bin_digits)
	{
		a_size = a->size;
		while (a_size)
		{
			if ((a->head->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			a_size--;
		}
		b_size = b->size;
		while (b_size)
		{
			pa(a, b);
			b_size--;
		}
		i++;
	}
}

