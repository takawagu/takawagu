#include <stdio.h>
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	bit = 0;
	while (i--)
	{
		bit = ((bit * 2) + (octet % 2));
		octet /= 2;
	}
	return (bit);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	print_bits(unsigned char octet)
{
	int				index;
	unsigned char	bit;

	index = 8;
	bit = 0;
	while (index--)
	{
		bit = ((octet >> index & 1) + '0');
		ft_putchar(bit);
	}
}

int	main(void)
{
	print_bits(2);
	ft_putchar('\n');
	print_bits(reverse_bits(2));
	ft_putchar('\n');
}