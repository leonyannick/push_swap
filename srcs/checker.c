/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:38:28 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/14 14:27:03 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	instrcmp(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(instr, "ra\n"))
		return (rotate(a, NORMAL), 1);
	else if (!ft_strcmp(instr, "rb\n"))
		return (rotate(b, NORMAL), 1);
	else if (!ft_strcmp(instr, "sa\n"))
		return (swap(a), 1);
	else if (!ft_strcmp(instr, "sb\n"))
		return (swap(b), 1);
	else if (!ft_strcmp(instr, "ss\n"))
		return (swap(a), swap(b), 1);
	else if (!ft_strcmp(instr, "pa\n"))
		return (push_y_to_x(a, b), 1);
	else if (!ft_strcmp(instr, "pb\n"))
		return (push_y_to_x(b, a), 1);
	else if (!ft_strcmp(instr, "rr\n"))
		return (rotate(a, NORMAL), rotate(b, NORMAL), 1);
	else if (!ft_strcmp(instr, "rra\n"))
		return (rotate(a, REVERSE), 1);
	else if (!ft_strcmp(instr, "rrb\n"))
		return (rotate(b, REVERSE), 1);
	else if (!ft_strcmp(instr, "rrr\n"))
		return (rotate(a, REVERSE), rotate(b, REVERSE), 1);
	else
		return (0);
}

int	checker(t_stack *a, t_stack *b)
{
	char	*instr;

	instr = get_next_line(0);
	while (instr)
	{
		if (!instrcmp(instr, a, b))
		{
			free(instr);
			return (0);
		}
		free(instr);
		instr = get_next_line(0);
	}
	free(instr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	if (!initialize_stacks(&a, &b) || !check_input(argc - 2, ++argv, a))
	{
		free_mem(a, b);
		return (write(2, "Error\n", 6), 0);
	}
	if (!checker(a, b))
	{
		free_mem(a, b);
		return (write(2, "Error\n", 6), 0);
	}
	if (is_sorted(a) && !b->size)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_mem(a, b);
	return (0);
}
