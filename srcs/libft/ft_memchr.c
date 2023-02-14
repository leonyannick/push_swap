/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:39:26 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 15:12:06 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	-scans n bytes of s and looks for 1st instance of c
	-interpreted as unsigned char
	-return value: pointer to matching byte or NULL if given c not occuring 

	TESTS:
	-n = 0
	-c = 0
	-c not in s
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*addr;

	addr = (unsigned char *) s;
	c = (unsigned char) c;
	while (n > 0)
	{
		if (*addr == c)
			return ((void *) addr);
		addr++;
		n--;
	}
	return (0);
}
