/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 09:45:47 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/20 11:02:28 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_check_input(int argc, char **argv)
{
	int		cl_arg;
	int		cl_argchr;
	long	num;

	if (argc < 2)
		return (0);
	cl_arg = 1;
	cl_argchr = 0;
	while (cl_arg < argc)
	{
		while (argv[cl_arg][cl_argchr])
		{
			if (!ft_isdigit(argv[cl_arg][cl_argchr]))
				return (0);
			cl_argchr++;
		}
		num = ft_atol(argv[cl_arg]);
		if (num > INT_MAX)
			return (0);
		cl_arg++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (!ft_check_input(argc, argv))
		return (write(2, "Error\n", 6), 0);
}
