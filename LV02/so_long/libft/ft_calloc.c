/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:16:06 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/09 15:22:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (count == 0 || size == 0)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		return (ptr);
	}
	if (count > __SIZE_MAX__ / size)
		return (NULL);
	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}

// #include <stdio.h>

// int	main(void)
// {
// 	size_t count;
// 	size_t size;
// 	const char *str;
// 	str = "Hello";
// 	void *memory;
// 	count = ft_strlen(str) + 1;
// 	size = sizeof(char);

// 	memory = (malloc(count * size));
// 	if (memory == NULL)
// 	{
// 		printf("メモリ確保に失敗しました\n");
// 		return (1);
// 	}
// 	else
// 	{
// 		printf("メモリ確保成功しました\n");
// 	}

// 	free(memory);
// 	return (0);
// }