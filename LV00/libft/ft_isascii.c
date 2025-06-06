/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:25:40 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/26 15:09:59 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
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

// 	c = 's';
// 	x = 200;
// 	printf("結果：%d\n", ft_isascii(c));
// 	printf("結果：%d\n", ft_isascii(x));
// 	return (0);
// }