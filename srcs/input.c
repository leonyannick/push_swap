/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:51:41 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/14 14:47:14 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

static void	freesplit(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	check_and_assign(int arg_idx, char **nums, int is_str, t_stack *a)
{
	t_frame	*frame;
	long	num;
	int		error_flag;

	while (arg_idx >= 0)
	{
		frame = malloc(sizeof(t_frame));
		if (!frame)
			return (0);
		num = ft_atol(nums[arg_idx], &error_flag);
		if (num < INT_MIN || num > INT_MAX || is_duplicate(a, num)
			|| error_flag)
		{
			if (is_str)
				freesplit(nums);
			return (free(frame), 0);
		}
		frame->value = num;
		push(a, frame);
		arg_idx--;
	}
	return (1);
}

int	check_input(int arg_idx, char **args, t_stack *a)
{
	char	**nums;
	int		is_str;

	is_str = 0;
	if (arg_idx < 0)
		return (0);
	if (arg_idx == 0)
	{
		nums = ft_split(args[0], ' ', &arg_idx);
		is_str = 1;
	}
	else
		nums = args;
	if (!check_and_assign(arg_idx, nums, is_str, a))
		return (0);
	if (is_str)
		freesplit(nums);
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
