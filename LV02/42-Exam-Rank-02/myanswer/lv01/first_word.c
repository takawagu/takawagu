#include <unistd.h>

int	ft_is_space(char c)
{
	if (9 <= c && c <= 13 || c == ' ')
		return (1);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	char *str;

	if (argc < 2)
		return (1);

	str = argv[1];

	while (*str && ft_is_space(*str))
		str++;

	while (*str && !ft_is_space(*str))
	{
		write(1, str, 1);
		str++;
	}
	return (0);
}