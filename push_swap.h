/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:56:45 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/20 14:29:46 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}t_stack;

//t_stack		*ft_push(t_stack **head, int value);
void		print_stack(t_stack *head);
t_stack		*pop(t_stack **head);
void		push(t_stack **head, int value);

#endif
