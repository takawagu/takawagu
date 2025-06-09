#include <unistd.h>

int	ft_to_upper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_snake_to_camel(char *str)
{
	int	upper_next;

	upper_next = 0;
	while (*str)
	{
		if (*str == '_')
		{
			upper_next = 1; // 次の文字を大文字化フラグ
		}
		else
		{
			if (upper_next)
			{
				ft_putchar((char)ft_to_upper(*str));
				upper_next = 0;
			}
			else
			{
				ft_putchar(*str);
			}
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_snake_to_camel(argv[1]);
	ft_putchar('\n');
	return (0);
}