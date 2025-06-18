#include <unistd.h>

int	ft_is_upper(char c)
{
	return (('A' <= c && c <= 'Z'));
}

int	ft_is_lower(char c)
{
	return (('a' <= c && c <= 'z'));
}

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	ft_put_13(char *str, int rot)
{
	if (ft_is_upper(*str))
	{
		*str = ('A' + (*str - 'A' + rot) % 26);
		ft_putchr(*str);
	}
	else if (ft_is_lower(*str))
	{
		*str = ('a' + (*str - 'a' + rot) % 26);
		ft_putchr(*str);
	}
	else
		ft_putchr(*str);
}

int	main(int argc, char **argv)
{
	int i;
	i = 0;
	int rot = 13;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			ft_put_13(&argv[1][i], rot);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}