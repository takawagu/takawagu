/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:38:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/01 16:47:26 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	if (s_len - start < len)
		len = s_len - start;
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (dst != NULL && s != NULL && i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char *s1 = ft_substr("Helloooooo!!", 3, 8);
// 	printf("%s\n", s1);
// 	free(s1);

// 	return (0);
// }