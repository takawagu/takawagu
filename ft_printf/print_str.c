/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:16:04 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 11:11:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *s)
{
	size_t	len;
	ssize_t	ret;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ret = write(1, s, len);
	if (ret < 0)
		return (-1);
	return ((int)ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*s;

// 	s = "Hello World";
// 	ft_print_str(s);
// }
