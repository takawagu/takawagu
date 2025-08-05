/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:16:41 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 23:25:57 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	str[] = "Hello World";
// 	int			c;
// 	void		*p;

// 	c = 'p';
// 	p = ft_memchr(str, c, ft_strlen(str) + 1);
// 	if (p != NULL)
// 		printf("見つかった文字:%c\n", *(char *)p);
// 	else
// 		printf("見つかりませんでした\n");
// 	return (0);
// }
