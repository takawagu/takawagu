/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:47:23 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:17 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putnbr_base(unsigned int n, const char *base)
{
	int	len;
	int	sub;

	len = 0;
	if (n >= 16)
	{
		sub = putnbr_base(n / 16, base);
		if (sub < 0)
			return (-1);
		len += sub;
	}
	if (write(1, &base[n % 16], 1) < 0)
		return (-1);
	return (len + 1);
}

int	print_hex(unsigned int xn, int uppercase)
{
	const char	*base;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (putnbr_base(xn, base));
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int	xn;

// 	xn = 4233237;
// 	print_hex(xn, 0);
// 	write(1, "\n", 1);
// 	print_hex(xn, 1);
// 	return (0);
// }
