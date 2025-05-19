/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:40:30 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/27 16:00:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	a;

// 	a = 'b';
// 	printf("変更前：%c\n", a);
// 	a = ft_toupper(a);
// 	printf("変更後：%c\n", a);
// 	return (0);
// }
