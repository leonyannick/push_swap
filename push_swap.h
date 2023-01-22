/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/22 21:10:36 by lbaumann         ###   ########.fr       */
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
	int			size;
}t_stack;



//t_stack		*ft_push(t_stack **head, int value);
// void		print_stack(t_stack *head);
// t_stack		*pop(t_stack **head);
// void		push(t_stack **head, int value);

#endif
