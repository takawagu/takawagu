#include <unistd.h>

char	*ft_find_end(char *str)
{
	while (*str != '\0')
	{
		str++;
	}
	return (str);
}

void	ft_putrev(char *str, char *start)
{
	str--;
	while (str >= start)
	{
		write(1, str, 1);
		str--;
	}
}

int	main(int argc, char *argv[])
{
	char	*end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	end = ft_find_end(argv[1]);
	ft_putrev(end, argv[1]);
	write(1, "\n", 1);
	return (0);
}
