/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann < lbaumann@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:32:40 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/13 10:29:08 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Outputs the string ’s’ to the given file descriptor
	followed by a newline.
*/
void	ft_putendl_fd(char *s, int fd)
{
	size_t	s_len;

	if (s == 0)
		return ;
	s_len = ft_strlen(s);
	write (fd, s, s_len);
	write (fd, "\n", 1);
}
