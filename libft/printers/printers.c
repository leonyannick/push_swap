/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:35:20 by lbaumann          #+#    #+#             */
/*   Updated: 2022/12/23 10:59:57 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printers.h"

/*
DESC:
	prints number in hexadecimal system
PARAMS:
	-base: base for hex system: "0123456789abcdef" needs to be entered for
	correct function
	-is_ptr: if 1 -> null pointer printed in different format and 0x added
	before address
	-n is of type unsigned long, as it is needed for %p,%x,%X in printf
	therefore negative values are casted
RET:
	-bytes written
	-returns -1 if write fails
*/
int	ft_puthex_fd(size_t n, char *base, int fd, int is_ptr)
{
	int		bytes_written;
	int		index;

	bytes_written = 0;
	if (base == 0)
		return (0);
	if (is_ptr && n == 0)
		return (ft_putstr_fd("(nil)", fd));
	if (is_ptr)
	{
		is_ptr = 0;
		if (ft_putstr_fd("0x", fd) < 0)
			return (-1);
		bytes_written += 2;
	}
	if (n > 15)
	{
		bytes_written += ft_puthex_fd(n / 16, base, fd, is_ptr);
	}
	index = n % 16;
	if (write(fd, &base[index], 1) < 0)
		return (-1);
	return (++bytes_written);
}
