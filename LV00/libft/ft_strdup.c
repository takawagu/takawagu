/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:07:22 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:13:07 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = ft_strlen(s);
	copy = ft_calloc(len + 1, sizeof(char));
	if (copy == NULL)
		return ((NULL));
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	return (copy);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char *s1;
// 	s1 = "Hello,World";
// 	printf("%s\n", ft_strdup(s1));
// 	return (0);
// }