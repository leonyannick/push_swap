/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/23 12:12:54 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_frame
{
	int				value;
	struct s_frame	*next;
}t_frame;

typedef struct s_stack
{
	t_frame		*head;
	t_frame		*tail;
	int			size;
}t_stack;

# define REVERSE 1
# define NORMAL 0


void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	print_stack(t_stack *stack);
void	clear_stack(t_stack *stack);

#endif
