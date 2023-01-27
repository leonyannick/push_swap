/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_x_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:05:57 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/24 13:06:51 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
		//tests for push_y_to_x
		t_stack	*b;
		b = malloc(sizeof(t_stack));
		b->size = 0;

		//normal swapping
		push(a, 5);
		push(a, 1);
		push(a, 3);
		printf("a before pa:\t");
		print_stack(a);
		push(b, 7);
		push(b, 2);
		push(b, 4);
		printf("b before pa:\t");
		print_stack(b);
		push_y_to_x(a, b);
		printf("a after pa:\t");
		print_stack(a);
		printf("b after pa:\t");
		print_stack(b);
		printf("\n");

		//empty stack y
		clear_stack(b);
		printf("a before pa:\t");
		print_stack(a);
		printf("b before pa:\t");
		print_stack(b);
		push_y_to_x(a, b);
		printf("a after pa:\t");
		print_stack(a);
		printf("b after pa:\t");
		print_stack(b);
}
