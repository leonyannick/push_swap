/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:36:20 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 10:45:41 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	behavior undefined if c not unsigned char value or EOF
*/
int	ft_toupper(int c)
{
	if (c <= 'z' && c >= 'a')
	{
		c -= 32;
		return (c);
	}
	return (c);
}
