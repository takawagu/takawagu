/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:28:36 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 07:14:57 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int		len;
	long	nb;

	nb = n;
	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	len = num_len(n);
	nb = n;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb >= 10)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	str[len] = nb + '0';
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;

// 	n = -2147483648;
// 	printf("%s\n", ft_itoa(n));
// 	return (0);
// }
