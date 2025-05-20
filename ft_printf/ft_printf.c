/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:49:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/21 07:27:54 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	i = 0;
	printed_len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
		printed_len += handle_format(format, args, &i);
	va_end(args);
	return (printed_len);
}

// #include "string.h"
// #include <limits.h>

// int	main(void)
// {
// 	int	n;
// 	int	un;

// 	n = INT_MAX;
// 	un = UINT_MAX;
// 	ft_printf("%c\n%s\n%d\n%i\naiueo\n%u\n%x\n%X\n%p\n%%\n", 'c', "string", n,
// 		n, un, un, un, &un);
// 	write(1, "\n", 1);
// 	printf("%c\n%s\n%d\n%i\naiueo\n%u\n%x\n%X\n%p\n%%\n", 'c', "string", n, n,
// 		un, un, un, &un);
// 	return (0);
// }

// #include "ft_printf.h"
// #include <stdio.h> // printf
// #include <unistd.h> // write

// int	main(void)
// {
// 	int	ret_ft;
// 	int	ret_std;

// 	// テスト1: 文字列
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
// 	int	ret;
// 	int	ret_std;
// 	int	ret_ft;

// 	close(1); // 標準出力を閉じる → fd 1 無効
// 	ret = ft_printf("This should fail\n");
// 	printf("ft_printf return: %d\n", ret); // ここは printf なので失敗する可能性あり
// 	return (0);
// 	// 不正なフォーマット指定子
// 	const char *test_cases[] = {"Test 1: [%q]",  // 未定義フォーマット
// 								"Test 2: [%~]",  // 特殊記号
// 								"Test 3: [%1]",  // 数字
// 								"Test 4: [%Z]",  // 未使用大文字
// 								"Test 5: [%]",   // 単独の %
// 								"Test 6: [%%x]", // 二重 %
// 								NULL};
// 	for (int i = 0; test_cases[i]; i++)
// 	{
// 		printf("=== %s ===\n", test_cases[i]);
// 		ret_ft = ft_printf("ft_printf: %s => ", test_cases[i]);
// 		ret_ft += ft_printf("%s", test_cases[i]);
// 		ft_printf(" | return (= %d\n", ret_ft);
// 		ret_std = printf("printf:    %s => ", test_cases[i]);
// 		ret_std += printf("%s", test_cases[i]);
// 		printf(" | return (= %d\n\n", ret_std);
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	ssize_t	ret;

	close(1); // 標準出力を閉じる
	ret = write(1, "Hello\n", 6);
	// 標準エラー出力に結果を表示
	dprintf(2, "write returned: %zd\n", ret);
	perror("write");
	return (0);
}
