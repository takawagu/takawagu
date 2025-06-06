/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:56:49 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/04 21:17:15 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int c;
// 	int x;
// 	int y;

// 	c = 's';
// 	x = 127;
// 	y = ' ';

// 	printf("結果：%d\n", ft_isascii(c));
// 	printf("結果：%d\n", ft_isascii(x));
// 	printf("結果：%d\n", ft_isascii(y));
// 	return (0);
// }