/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:04:07 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/24 13:05:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	//tests for swap:
	t_stack	*a;
	a = malloc(sizeof(t_stack));
	a->size = 0;

	//empty stack swap
	a->head = NULL;
	swap(a);
	print_stack(a);

	//one element swap
	push(a, 5);push_y_to_x(a, b);
	print_stack(a);
	swap(a);
	printf("swapped:\n");
	print_stack(a);
	printf("\n");
	
	//normal swap
	push(a, 1);
	push(a, 3);
	print_stack(a);
	swap(a);
	printf("swapped:\n");
	print_stack(a);
	printf("\n");
}
