/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:14:25 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/19 16:10:11 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	ssize_t	ret;

	ret = write(1, &c, 1);
	if (ret < 0)
		return (-1);
	return ((int)ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char c;
// 	c = '2';
// 	print_char(c);
// }