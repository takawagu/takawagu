/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:58:53 by takawagu          #+#    #+#             */
/*   Updated: 2025/04/27 16:00:06 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int a;

// 	a = 'Q';
// 	printf("変更前：%c\n", a);
// 	a = ft_tolower(a);
// 	printf("変更後：%c\n", a);
// 	return (0);
// }