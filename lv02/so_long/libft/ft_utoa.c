/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:24:58 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/24 13:41:03 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	num_len_unsigned_int(unsigned int u_num)
{
	unsigned int	len;

	len = 1;
	while (u_num >= 10)
	{
		u_num /= 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = num_len_unsigned_int(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	unsigned int un;
// 	un = 4294967295;
// 	printf("%s\n", ft_utoa(un));

// 	return (0);
// }