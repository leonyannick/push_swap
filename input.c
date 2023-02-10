/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:43:34 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/08 15:47:59 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_frame	*frame;

	if (arg_idx < 0)
		return (0);
	if (arg_idx == 0)
		nums = ft_split(nums[0], ' ', &arg_idx);
	if (!nums[0])
		return (0);
	while (arg_idx >= 0)
	{
		frame = malloc(sizeof(t_frame));
		if (!frame)
			return (0);
		num = ft_atol(nums[arg_idx], &error_flag);
		if (num < INT_MIN || num > INT_MAX || is_duplicate(a, num)
			|| error_flag)
			return (0);
		frame->index_s = -1;
		frame->value = num;
		push(a, frame);
		arg_idx--;
	}
	return (1);
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
