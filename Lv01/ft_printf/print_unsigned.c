/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:19:00 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/24 13:50:00 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int un)
{
	char			*str;
	unsigned int	len;

	str = ft_utoa(un);
	if (!str)
		return (-1);
	len = print_str(str);
	free(str);
	return (len);
}

// int	main(void)
// {
// 	unsigned int	un;

// 	un = 4294967295;
// 	print_unsigned(un);
// 	return (0);
// }
