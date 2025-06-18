#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}
int	ft_islower(char c)
{
	return ('a' <= c && c <= 'z');
}

int	ft_isupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

void	ft_put_rotone(char *str, int rot)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_islower(str[i]))
		{
			str[i] = ('a' + ((str[i] - 'a') + rot) % 26);
			ft_putchr(str[i]);
		}
		else if (ft_isupper(str[i]))
		{
			str[i] = ('A' + ((str[i] - 'A') + rot) % 26);
			ft_putchr(str[i]);
		}
		else
			ft_putchr(str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	rot;

	i = 0;
	rot = 1;
	if (argc == 2)
		ft_put_rotone(&argv[1][i], rot);
	ft_putchr('\n');
	return (0);
}
