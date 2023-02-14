/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_stack_ops3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:33:36 by lbaumann          #+#    #+#             */
/*   Updated: 2023/02/13 14:09:39 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	rotate(a, REVERSE);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rotate(a, REVERSE);
	rotate(b, REVERSE);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	rotate(a, NORMAL);
	rotate(b, NORMAL);
}
