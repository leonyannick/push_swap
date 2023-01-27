/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:14:38 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/27 14:44:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	insertion_sort(t_stack *a)
{
	int	i;
	int	j;
	int	cnt;

	i = 1;
	while (i < a->size)
	{
		j = i;
		cnt = 1;
		while (j > 0 && (a->head->value) > (a->head->next->value))
		{
			sa(a);
			if (j > 1)
			{
				rra(a);
				cnt++;
			}
			j--;
		}
		while (cnt)
		{
			ra(a);
			cnt--;
		}
		i++;
	}
	ra(a);
}
