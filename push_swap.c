/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/29 18:23:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	is_duplicate(t_stack *stack, int num)
{
	t_frame		*temp;
	int			temp_stack_size;

	temp_stack_size = stack->size;
	temp = stack->head;
	while (temp_stack_size)
	{
		if (num == temp->value)
			return (1);
		temp = temp->next;
		temp_stack_size--;
	}
	return (0);
}

int	check_input(int arg_idx, char **nums, t_stack *a)
{
	int		error_flag;
	long	num;

	if (arg_idx < 0)
		return (0);
	if (arg_idx == 0)
		nums = ft_split(nums[0], ' ', &arg_idx);
	if (!nums[0])
		return (0);
	while (arg_idx >= 0)
	{
		num = ft_atol(nums[arg_idx], &error_flag);
		if (num > INT_MAX || is_duplicate(a, num) || error_flag)
			return (0);
		push(a, num);
		a->head->index = -1;
		arg_idx--;
	}
	return (1);
}

void	free_mem(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	if (a)
		free(a);
	if (b)
		free(b);
}

void	print_stack(t_stack *stack)
{
	t_frame	*temp;
	int		temp_stack_size;

	temp_stack_size = stack->size;
	temp = stack->head;
	while (temp_stack_size)
	{
		/* printf("prev: %i, ", temp->prev->value);
		printf("val: \033[1;31m%i\033[0m ", temp->value);
		printf("next: %i -> , ", temp->next->value); */
		printf("\033[1;31m%i\033[0m index:%i -> ", temp->value, temp->index);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("\n");
}

int	is_sorted(t_stack *a)
{
	int			nvals;
	int			ncompares;
	t_frame		*head;
	t_frame		*val;

	head = a->head;
	nvals = (a->size - 1);
	while (nvals)
	{
		ncompares = nvals;
		val = head;
		while (ncompares)
		{
			if ((val->value) > (val->next->value))
				return (0);
			val = val->next;
			ncompares--;
		}
		val = head->next;
		head = head->next;
		nvals--;
	}
	return (1);
}

int	is_rev_sorted(t_stack *a)
{
	int			nvals;
	int			ncompares;
	t_frame		*head;
	t_frame		*val;

	head = a->head->prev;
	nvals = (a->size - 1);
	while (nvals)
	{
		ncompares = nvals;
		val = head;
		while (ncompares)
		{
			if ((val->value) > (val->prev->value))
				return (0);
			val = val->prev;
			ncompares--;
		}
		val = head->prev;
		head = head->prev;
		nvals--;
	}
	return (1);
}

int	initialize_stacks(t_stack **a, t_stack **b)
{
	*b = malloc(sizeof(t_stack));
	*a = malloc(sizeof(t_stack));
	if (!*a || !*b)
	{
		free_mem(*a, *b);
		return (0);
	}
	(*a)->size = 0;
	(*b)->size = 0;
	return (1);
}

void	n_rotate(t_stack *stack, int n)
{
	
	while (n)
	{
		ra(stack);
		n--;
	}
}

void	sort_3(t_stack *a)
{
	int	head_val;
	int	next_val;
	int	prev_val;

	head_val = a->head->value;
	next_val = a->head->next->value;
	prev_val = a->head->prev->value;
	if (head_val < next_val && head_val < prev_val && prev_val < next_val)
	{
		sa(a);
		ra(a);
	}
	else if (head_val > next_val && head_val > prev_val && prev_val > next_val)
		ra(a);
	else if (head_val > next_val && head_val > prev_val && prev_val < next_val)
	{
		sa(a);
		rra(a);
	}
	else if (head_val > next_val && head_val < prev_val)
		sa(a);
	else
		rra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
	sort_3(a);
	
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	
	argv++;
	argc -= 2;
	if (!initialize_stacks(&a, &b) || !check_input(argc, argv, a))
	{
		free_mem(a, b);
		return (write(2, "Error\n", 6), 0);
	}
	/* print_stack(a);
	if (is_sorted(a))
	{
		printf("sorted\n");
		return (0);
	}
	if (a->size == 3)
		sort_3(a); */
	print_stack(a);
	normalize(a);
	print_stack(a);

}
