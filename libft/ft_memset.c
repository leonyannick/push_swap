/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:32:13 by lbaumann          #+#    #+#             */
/*   Updated: 2022/11/30 18:40:12 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESC: fills first n bytes of memory area (pointed to by s) with constant byte c
	RETURN: returns pointer to memory area
	TESTS: -
*/
void	*ft_memset(void *s, int c, size_t n)
{
	char	*addr;

	addr = (char *) s;
	while (n)
	{
		*addr = c;
		addr++;
		n--;
	}
	return ((char *) s);
}

/* int	main(void)
{
	char str[] = "test";
	printf("%s\n", str);
	memset(&str, 'c', 3);
	printf("%s\n", str);
} */
