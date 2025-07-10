/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:28:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:35 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	putnbr_base_ulong(unsigned long n, const char *base)
{
	int	len;
	int	sub;

	len = 0;
	if (n >= 16)
	{
		sub = putnbr_base_ulong(n / 16, base);
		if (sub < 0)
			return (-1);
		len += sub;
	}
	if (write(1, &base[n % 16], 1) < 0)
		return (-1);
	return (len + 1);
}

int	print_pointer(void *ptr)
{
	uintptr_t	addr;
	int			len;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	addr = (uintptr_t)ptr;
	if (write(1, "0x", 2) < 0)
		return (-1);
	len = putnbr_base_ulong(addr, "0123456789abcdef");
	if (len < 0)
		return (-1);
	return (len + 2);
}

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello";
// 	print_pointer(s);
// 	return (0);
// }
