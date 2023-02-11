/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:56:09 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/11 17:45:41 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int	bin_digits;
	int	i;
	int	n;

	bin_digits = 1;
	i = 0;
	while ((a->size - 1) >> bin_digits)
		bin_digits++;
	while(i < bin_digits)
	{
		n = a->size;
		while (n)
		{
			if ((a->head->index_s >> i) & 1)
				ra(a);
			else
				pb(a, b);
			n--;
		}
		while (b->size)
			pa(a, b);
		i++;
	}
}

