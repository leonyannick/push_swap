/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:14:38 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/13 09:47:37 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insertion_sort(t_stack *a, int i, int j, int cnt)
{
	i = 1;
	while (i < a->size)
	{
		j = i;
		cnt = 1;
		while (j > 0 && (a->head->value) > (a->head->next->value))
		{
			swap(a);
			if (j > 1)
			{
				rotate(a, REVERSE);
				cnt++;
			}
			j--;
		}
		while (cnt)
		{
			rotate(a, NORMAL);
			cnt--;
		}
		i++;
	}
	rotate(a, NORMAL);
}
