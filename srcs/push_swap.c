/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/14 18:01:16 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			chunksz;

	if (argc == 1)
		return (0);
	if (!initialize_stacks(&a, &b) || !check_input(argc - 2, ++argv, a))
	{
		free_mem(a, b);
		return (write(2, "Error\n", 6), 0);
	}
	if (is_sorted(a))
	{
		free_mem(a, b);
		return (0);
	}
	assign_index(a, a->size);
	chunksz = a->size / 3;
	create_chunks(a, b, chunksz);
	sort_3(a);
	cost_sort(a, b);
	free_mem(a, b);
}
