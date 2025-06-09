#include <unistd.h>

int	ft_isupper(int c)
{
	return (('A' <= c && c <= 'Z'));
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c = c + ('a' - 'A');
	return (c);
}
void	ft_puthcar(char c)
{
	write(1, &c, 1);
}

void	ft_camel_to_snake(char *str)
{
	while (*str)
	{
		if (ft_isupper(*str))
		{
			ft_puthcar('_');
			*str = ft_tolower(*str);
		}
		ft_puthcar(*str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_camel_to_snake(argv[1]);
	ft_puthcar('\n');
	return (0);
}
