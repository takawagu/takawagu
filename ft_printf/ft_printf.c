/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:49:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/15 12:54:31 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	i = 0;
	printed_len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (format[i])
		printed_len += handle_format(format, args, &i);
	va_end(args);
	return (printed_len);
}

// #include "string.h"
// #include <limits.h>

// int	main(void)
// {
// 	int n;
// 	int un;
// 	n = INT_MAX;
// 	un = UINT_MAX;

// 	ft_printf("%c\n%s\n%d\n%i\n%u\n%x\n%X\n%p\n%%\n", 'c', "string", n, n, un,
// 		un, un, &un);
// 	write(1, "\n", 1);
// 	printf("%c\n%s\n%d\n%i\n%u\n%x\n%X\n%p\n%%\n", 'c', "string", n, n, un, un,
// 		un, &un);
// 	return (0);
// }