/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:14:19 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/13 10:34:10 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	PARAMETERS:
		lst: The address of a pointer to a node.
		del: The address of the function used to delete
		the content of the node.
	DESCRIPTION:
		Deletes and frees the given node and every
		successor of that node, using the function ’del’
		and free(3).
		Finally, the pointer to the list must be set to
		NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (lst == 0 || del == 0)
		return ;
	while (*lst != 0)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = 0;
}
