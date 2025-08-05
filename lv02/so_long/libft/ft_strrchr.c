/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 07:21:29 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/05 00:12:21 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (last);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*s;
// 	int			c;

// 	s = "HelloWorld Windows";
// 	c = 'a';
// 	printf("抽出：%s", ft_strrchr(s, c));
// 	return (0);
// }
