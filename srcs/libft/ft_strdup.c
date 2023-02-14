/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:29:45 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/08 16:51:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESC: returns pointer to new string (duplicate of s)
	RETURN:	pointer
			NULL if insufficient memory
*/
char	*ft_strdup(const char *s)
{
	int		len;
	char	*dup;
	int		i;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = 0;
	return (dup);
}
