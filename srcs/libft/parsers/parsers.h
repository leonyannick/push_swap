/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:58:54 by lbaumann          #+#    #+#             */
/*   Updated: 2023/01/24 11:11:56 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H

# include "../printers/printers.h"
# include "../libft.h"
# include <stdarg.h>

# define HEX_UC "0123456789ABCDEF"
# define HEX_LC "0123456789abcdef"
# define STD_OUT 1

int	ft_parser(char *format, va_list args, int *bytes_written);
int	ft_format(char *format, va_list args);

#endif
