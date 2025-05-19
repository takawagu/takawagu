/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:28:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/13 10:45:19 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	putnbr_base_ulong(unsigned long n, const char *base)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
		len += putnbr_base_ulong(n / 16, base);
	write(1, &base[n % 16], 1);
	return (len + 1);
}

int	print_pointer(void *ptr)
{
	uintptr_t	addr;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (uintptr_t)ptr;
	write(1, "0x", 2);
	return (2 + putnbr_base_ulong(addr, "0123456789abcdef"));
}

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello";
// 	print_pointer(s);
// 	return (0);
// }
