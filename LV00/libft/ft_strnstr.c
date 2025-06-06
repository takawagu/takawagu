/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:11:46 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/28 17:15:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && little[j] != '\0' && big[i + j] == little[j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*big = "Harry Potter";
// 	const char	*little = "Pot";
// 	char		*ptr;

// 	ptr = ft_strnstr(big, little, 10);
// 	if (ptr != NULL)
// 	{
// 		printf("ポインタ値: %p\n", (void *)ptr);
// 		printf("最初の文字: %c\n", *ptr);
// 		printf("以降の文字列: %s\n", ptr);
// 	}
// 	else
// 	{
// 		printf("見つかりませんでした\n");
// 	}
// 	return (0);
// }
