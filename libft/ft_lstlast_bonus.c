/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:54:27 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/12 09:57:38 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	PARAMETERS:
		lst, beginning of list
	DESCRIPTION:
		returns last node of the list
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}
