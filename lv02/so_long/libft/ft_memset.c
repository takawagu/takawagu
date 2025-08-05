/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:08:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:21:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "sjaojda";
// 	void	*address;
// 	int		c;
// 	size_t	len;

// 	c = '1';
// 	len = 7;
// 	address = &str;
// 	printf("変更前;%s\n", str);
// 	ft_memset(address, c, len);
// 	printf("変更後;%s\n", str);
// 	return (0);
// }
