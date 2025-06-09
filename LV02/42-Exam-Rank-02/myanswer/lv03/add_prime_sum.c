#include <unistd.h>

// 数字に変換（atoiの代わり）
int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}
// 数字を出力する（再帰で1文字ずつ）
void	putnbr(int n)
{
	char	c;

	if (n > 9)
		putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

// 素数判定
int	is_prime(int n)
{
	int	i;

	i = 2;
	if (n < 2)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int n, sum = 0, i = 2;
	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
		putnbr(sum);
	}
	else
	{
		write(1, "0", 1);
	}
	write(1, "\n", 1);
	return (0);
}
