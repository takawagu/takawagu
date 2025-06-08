#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}

int	main(void)
{
	int n;
	n = 1;

	while (n <= 100)
	{
		if (((n % 3) == 0) && ((n % 5) == 0))
		{
			ft_putstr("fizzbuzz");
		}

		else if ((n % 3) == 0)
		{
			ft_putstr("fizz");
		}
		else if ((n % 5) == 0)
		{
			ft_putstr("buzz");
		}
		else
			ft_putnbr(n);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}