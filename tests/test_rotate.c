/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:06:58 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/25 13:21:22 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(void)
{
	t_stack		*a;
	t_stack		*b;
	
	b = malloc(sizeof(t_stack));
	a = malloc(sizeof(t_stack));
	if (!a || !b)
	{
		return (write(2, "Error\n", 6), 0);
	}
	a->size = 0;
	
	//tests for rotate
	push(a, 5);
	push(a, 1);
	push(a, 3);
	push(a, 7);
	push(a, 9);
	printf("a before reverse rotate:\t");
	print_stack(a);
	rotate(a, REVERSE);
	printf("a after reverse rotate:\t");
	print_stack(a);
	printf("a after rotated back:\t");
	rotate(a, NORMAL);
	print_stack(a);
	rotate(a, NORMAL);
	rotate(a, NORMAL);
	printf("a after 2 rot:\t");
	print_stack(a);
	rotate(a, NORMAL);
	rotate(a, NORMAL);
	rotate(a, NORMAL);
	printf("a after 5 rot:\t");
	print_stack(a);
	rotate(a, REVERSE);
	rotate(a, REVERSE);
	printf("a after 2 reverse rot:\t");
	print_stack(a);
	rotate(a, REVERSE);
	rotate(a, REVERSE);
	rotate(a, REVERSE);
	printf("a after 5 revsere rot:\t");
	print_stack(a);
}
