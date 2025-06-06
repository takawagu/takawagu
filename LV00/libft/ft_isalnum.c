/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:15:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/26 14:05:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c
			&& c <= '9'))
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
// 	int	c;
// 	int	x;

// 	c = 's';
// 	x = ' ';
// 	printf("結果：%d\n", ft_isalnum(c));
// 	printf("結果：%d\n", ft_isalnum(x));
// 	return (0);
// }
