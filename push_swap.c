/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/28 00:08:30 by lbaumann         ###   ########.fr       */
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

/* int	process_str(char* str, t_stack *a)
{
	int i;
	int is_string;

	i = 0;
	is_string = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			is_string = 1;
		i++;
	}
	if (!is_string)
		return (0);
	
} */

int	check_input(int arg_idx, char **nums, t_stack *a)
{
	int		chr_idx;
	long	num;

	if (arg_idx < 0)
		return (0);
	if (arg_idx == 0)
		nums = ft_split(nums[0], ' ', &arg_idx);
	if (!nums[0])
		return (0);
	chr_idx = 0;
	while (arg_idx >= 0)
	{
		while (nums[arg_idx][chr_idx])
		{
			if (!ft_isdigit(nums[arg_idx][chr_idx]))
				return (0);
			chr_idx++;
		}
		num = ft_atol(nums[arg_idx]);
		if (num > INT_MAX || is_duplicate(a, num))
			return (0);
		push(a, num);
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
		printf("\033[1;31m%i\033[0m-> ", temp->value);
		temp = temp->next;
		temp_stack_size--;
	}
	printf("\n");
}

int	is_sorted(t_stack *a)
{
	int			i;
	int			j;
	t_frame		*head;

	head = a->head;
	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < (a->size - 1))
		{
			if ((a->head->value) > (a->head->next->value))
			{
				a->head = head;
				return (0);
			}
			a->head = a->head->next;
			j++;
		}
		i++;
	}
	a->head = head;
	return (1);
}

/*
gcc push_swap.c push_pop.c stack_operations.c libft/ft_split.c libft/ft_isdigit.c libft/ft_atol.c libft/ft_strlcpy.c libft/ft_strlen.c libft/ft_printf.c libft/parsers/parsers.c libft/printers/printers.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c
*/
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
	print_stack(a);
	//normalize(a, a->head);
	//print_stack(a);
	//insertion_sort(a);
	// if (is_sorted(a))
	// 	printf("sorted\n");
	// print_stack(a);
	//free_mem(a, b);
}
