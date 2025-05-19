/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:36:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/12 08:56:58 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = "sjaojda";
// 	void *address;
// 	size_t len;

// 	len = 7;
// 	address = &str;
// 	printf("変更前;%s\n", str);
// 	ft_bzero(address, len);
// 	printf("変更後;%s\n", str);
// 	return (0);
// }