/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:49:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/24 16:16:01 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;
	int		tmp;

	i = 0;
	printed_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		tmp = handle_format(format, args, &i);
		if (tmp < 0)
		{
			va_end(args);
			return (-1);
		}
		printed_len += tmp;
	}
	va_end(args);
	return (printed_len);
}

// int	main(void)
// {
// 	int	ret_ft;
// 	int	ret_std;

// 	// テスト1:
// 	// 	文字列
// 	ret_ft = ft_printf("ft_printf: [%s]\n", "Hello World");
// 	ret_std = printf("printf:    [%s]\n", "Hello World");
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト2: 整数
// 	ret_ft = ft_printf("ft_printf: [%d]\n", 12345);
// 	ret_std = printf("printf:    [%d]\n", 12345);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト3: NULL文字列
// 	ret_ft = ft_printf("ft_printf: [%s]\n", (char *)NULL);
// 	ret_std = printf("printf:    [%s]\n", (char *)NULL);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	// テスト4: ポインタ
// 	ret_ft = ft_printf("ft_printf: [%p]\n", (void *)0x1234);
// 	ret_std = printf("printf:    [%p]\n", (void *)0x1234);
// 	printf("Return ft_printf: %d\n", ret_ft);
// 	printf("Return printf:    %d\n", ret_std);
// 	return (0);
// }

// #include <stdio.h>
// #include <unistd.h>

// int	main(void)
// {
// 	ssize_t	ret;

// 	close(1); // 標準出力を閉じる
// 	ret = write(1, "Hello\n", 6);
// 	// 標準エラー出力に結果を表示
// 	dprintf(2, "write returned: %zd\n", ret);
// 	perror("write");
// 	return (0);
// }

// #include "ft_printf.h"
// #include <stdio.h>

// int	main(void)
// {
// 	int	result;

// 	result = ft_printf("テスト:さｂじゃ%"); // ← 不完全な % を渡す
// 	printf("\n戻り値: %d\n", result);
// 	return (0);
// }

// int	main(void)
// {
// 	char			*p;
// 	int				d;
// 	unsigned int	u_num;
// 	char			a;
// 	char			*s;
// 	int				ret1;
// 	int				ret2;

// 	d = 0;
// 	u_num = UINT_MAX;
// 	p = &a;
// 	s = "%k";
// 	ret1 = printf("%X,%x,%s", u_num, u_num, s);
// 	printf("\n");
// 	ret2 = ft_printf("%X,%x,%s", u_num, u_num, s);
// 	printf("\n");
// 	printf("%d", ret1);
// 	printf("\n");
// 	printf("%d", ret2);
// 	printf("\n");
// 	return (0);
// }
