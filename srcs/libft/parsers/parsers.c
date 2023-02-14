/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:00:42 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/24 11:18:58 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsers.h"

/*
DESC:
	-loops through fromat string and writes each char
	-if format specifier % is detected ft_format is called with pointer of
	current argument and handles each case
	-bytes written is increased at adress for each char or with return
	from format
RET:
	-returns -1 in case write fails (return from format or putchar)
	-returns 0 in case of no failures
*/
int	ft_parser(char *format, va_list args, int *bytes_written)
{
	int	i;
	int	temp;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			temp = ft_format(&format[i], args);
			i++;
			if (temp < 0)
				return (-1);
			(*bytes_written) += temp;
		}
		else
		{
			if (ft_putchar_fd(format[i], 1) < 0)
				return (-1);
			(*bytes_written)++;
			i++;
		}
	}
	return (0);
}

/*
PARAMETERS: 
	-int *i: iterator from ft_parser

DESCRIPTION:
	-checks which conversion needs to be handled and calls the repectiveprinter
	functions
	-increases iterator i by one, so looping can continue in ft_parser
RETURN:
	-gets the number of chars printed from the printer functions
	and gives them back to ft_parser
	-on error returns -1
	-if none of the listed spefifiers is found -1 is returned
*/
int	ft_format(char *format, va_list args)
{
	if (*format == 'c')
		return (ft_putchar_fd(va_arg(args, int), STD_OUT));
	else if (*format == 's')
		return (ft_putstr_fd(va_arg(args, char *), STD_OUT));
	else if (*format == 'p')
		return (ft_puthex_fd(va_arg(args, long), HEX_LC, STD_OUT, 1));
	else if (*format == 'd' || *format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), STD_OUT));
	else if (*format == 'u')
		return (ft_putnbr_fd(va_arg(args, unsigned int), STD_OUT));
	else if (*format == 'X')
		return (ft_puthex_fd(va_arg(args, unsigned int), HEX_UC, STD_OUT, 0));
	else if (*format == 'x')
		return (ft_puthex_fd(va_arg(args, unsigned int), HEX_LC, STD_OUT, 0));
	else if (*format == '%')
		return (ft_putchar_fd('%', STD_OUT));
	else
		return (-1);
}
