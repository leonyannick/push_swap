/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:37:18 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 14:51:04 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION:
		compares first (at most) n bytes of strings s1 and s2
	RETURN:
		integer less 0, if s1 (n bytes) less than s2
		0 if equal
		integer bigger 0, if s1 (n bytes) more than s2
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && *s2 && (n - 1) > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char test[] = "abc\375xx";
	printf("%i\n", 'd');
	unsigned int t = (unsigned int) test[3];
	printf("%i\n", t);
	printf("%d\n", ft_strncmp("Hallo", "Halio", 5));
	printf("%d\n", ft_strncmp("Hallo", "Halio", 3));
	printf("%d\n", ft_strncmp("Hallo", "j", 5));
} */
