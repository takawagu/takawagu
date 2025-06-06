/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 10:26:31 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:23:07 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = dst;
	s = src;
	if (d == s || len == 0)
	{
		return (d);
	}
	else if (d < s)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len--)
			d[len] = s[len];
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s1[] = "hello world!";
// 	char	s2[] = "hello world!";

// 	ft_memmove(s1 + 6, s1, 5);
// 	memmove(s2 + 6, s2, 5);
// 	printf("ft_memmove overlap result : %s\n", s1);
// 	printf("   memmove overlap result : %s\n", s2);
// 	return (0);
// }
