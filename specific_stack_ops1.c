/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_stack_ops1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:35:57 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/11 17:33:57 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack *a)
{
	ft_printf("sa\n");
	swap(a);
}

void sb(t_stack *b)
{
	ft_printf("sb\n");
	swap(b);
}

void ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}

void pa(t_stack *a, t_stack *b)
{
	ft_printf("pa\n");
	push_y_to_x(a, b);
}
