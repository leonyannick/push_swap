/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_stack_ops2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:33:20 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:37 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	ft_printf("pb\n");
	push_y_to_x(b, a);
}

void	ra(t_stack *a)
{
	ft_printf("ra\n");
	rotate(a, NORMAL);
}

void	rb(t_stack *b)
{
	ft_printf("rb\n");
	rotate(b, NORMAL);
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	rotate(b, REVERSE);
}
