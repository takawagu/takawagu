#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_bits(unsigned char octet)
{
	int				index;
	unsigned char	bit;

	index = 8;
	while (index--)
	{
		bit = (((octet >> index) & 1) + '0');
		ft_putchar(bit);
	}
}

#include <stdlib.h> // exit, strtol

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		// 使い方表示
		write(1, "Usage: ./print_bits <0-255>\n", 28);
		return (EXIT_FAILURE);
	}

	long val = strtol(argv[1], NULL, 10);
	if (val < 0 || val > 255)
	{
		write(1, "Error: must be 0-255\n", 22);
		return (EXIT_FAILURE);
	}

	print_bits((unsigned char)val);
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}