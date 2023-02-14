/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:32:52 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/13 10:34:32 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	PARAMETERS:
		lst: The address of a pointer to a node.
		f: The address of the function used to iterate on
		the list.
	DESCRIPTION:
		Iterates the list ’lst’ and applies the function
		’f’ on the content of each node.
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == 0 || f == 0)
		return ;
	while (lst != 0)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
