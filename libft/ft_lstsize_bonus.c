/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:44:46 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/13 10:33:07 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	PARAMETERS:
		lst: beginning of list
	DESCRIPTION:
		counts number of nodes
*/
int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == 0)
		return (0);
	size = 0;
	while (lst != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
