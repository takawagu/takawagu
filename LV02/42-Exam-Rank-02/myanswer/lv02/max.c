#include <stdio.h>
#include <stdlib.h> // EXIT_SUCCESS
#include <unistd.h> // write STDOUT_FILENO

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				m;

	if (len == 0 || tab == NULL)
		return (0);
	i = 1;
	m = tab[0];
	while (i < len)
	{
		if (tab[i] > m)
			m = tab[i];
		i++;
	}
	return (m);
}

static void	ft_putchar(char character)
{
	write(1, &character, 1);
}

int	main(void)
{
	int arr[4];

	arr[0] = 7;
	arr[1] = 2;
	arr[2] = 4;
	arr[3] = 9;
	ft_putchar(max(arr, 4) + '0');
	ft_putchar(10);
	ft_putchar(max(NULL, 4) + '0');
	ft_putchar('\n');
	ft_putchar(max(arr, 0) + '0');
	ft_putchar('\n');
	return (EXIT_SUCCESS);
}