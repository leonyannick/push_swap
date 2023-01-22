/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:55:25 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 15:21:22 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while ((n - 1) > 0)
	{
		if (*a1 != *a2)
			break ;
		a1++;
		a2++;
		n--;
	}
	return (*a1 - *a2);
}
