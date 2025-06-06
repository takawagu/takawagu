/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:35:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:21:01 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	srclen = ft_strlen(src);
	i = 0;
	while (dstlen < size && dst[dstlen])
		dstlen++;
	if (dstlen == size)
		return (size + srclen);
	while (src[i] && (dstlen + i + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if ((dstlen + i) < size)
		dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char s[] = "worlddd";
// 	char d[] = "Hello";
// 	ft_strlcat(d, s, 4);
// 	printf("%s\n", d);
// 	printf("%zu\n", ft_strlcat(d, s, 4));
// 	return (0);
// }