/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:31:16 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/13 10:45:55 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	char			*str;
	unsigned int	len;

	str = ft_itoa(n);
	if (!str)
		return (0);
	len = print_str(str);
	free(str);
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	n;

// 	n = 21010;
// 	ft_print_int(n);
// 	return (0);
// }
