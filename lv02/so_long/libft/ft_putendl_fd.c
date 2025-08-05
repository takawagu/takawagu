/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 19:40:44 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/02 20:01:37 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}

// #include <stdio.h>

// int	main(void)

// {
// 	char *str;
// 	str = "Hello World";

// 	ft_putendl_fd(str, 1);
// 	printf("%s\n", "こんにちは");
// 	return (0);
// }
