/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:06:45 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/13 10:38:26 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	PARAMETER:
		s: The string on which to iterate.
		f: The function to apply to each character.
	DESCRIPTION:
		Applies the function ’f’ on each character of
		the string passed as argument, passing its index
		as first argument. Each character is passed by
		address to ’f’ to be modified if necessary
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	if (s == 0 || f == 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* void	test2(unsigned int i, char *c)
{
	*c += i;
}

#include <stdio.h>

int	main(void)
{
	char s[] = "hello world";
	printf("original before: %s\n", s);
	ft_striteri(s, test2);
	printf("original after: %s\n", s);
} */
