int	ft_atoi_base(const char *str, int str_base)
{
	char	*base;
	int		i;
	int		sign;
	int		result;
	int		j;
	char	c;

	base = "0123456789abcdef";
	i = 0;
	sign = 1;
	result = 0;
	// マイナス対応
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	// 1文字ずつ処理
	while (str[i])
	{
		// 小文字化（大文字対応）
		c = str[i];
		if (c >= 'A' && c <= 'F')
			c = c + ('a' - 'A');
		// base 内で何番目の文字か探す
		j = 0;
		while (j < str_base && base[j] != c)
			j++;
		// 見つかった場合だけ result に反映
		if (j < str_base)
			result = result * str_base + j;
		else
			break ; // 見つからない文字が来たら終了
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("A", 16));
	printf("%d\n", ft_atoi_base("B", 16));
	printf("%d\n", ft_atoi_base("C", 16));
	printf("%d\n", ft_atoi_base("D", 16));
	printf("%d\n", ft_atoi_base("e", 16));
	printf("%d\n", ft_atoi_base("E", 16));
	return (0);
}
