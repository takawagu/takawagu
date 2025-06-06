/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:41:40 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 11:20:46 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dispatch_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (print_str(va_arg(args, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int)));
	else if (specifier == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (specifier == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (specifier == '%')
		return (write(1, "%", 1));
	return (-1);
}

int	handle_format(const char *format, va_list args, int *index)
{
	int		tmp;
	ssize_t	write_ret_percent;
	ssize_t	write_ret_specifier;

	if (format[*index] == '%')
	{
		if (format[*index + 1] == '\0')
			return (-1);
		tmp = dispatch_format(format[*index + 1], args);
		if (tmp < 0)
		{
			write_ret_percent = write(1, &format[*index], 1);
			write_ret_specifier = write(1, &format[*index + 1], 1);
			if (write_ret_percent < 0 || write_ret_specifier < 0)
				return (-1);
			tmp = (int)(write_ret_percent + write_ret_specifier);
		}
		*index += 2;
		return (tmp);
	}
	write_ret_percent = write(1, &format[*index], 1);
	if (write_ret_percent < 0)
		return (-1);
	(*index)++;
	return (1);
}
