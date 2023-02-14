/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:29:33 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 11:08:01 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s != 0)
	{
		size++;
		s++;
	}
	return (size);
}

/* int	main(void)
{
	char test[] = "kurios";

	printf("%i", ft_strlen(test));
} */
