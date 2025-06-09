#include <stdlib.h>

static int	ft_absolute_value(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

int	*ft_range(int start, int end)
{
	int size;
	int step;
	int *tab;
	int i;

	i = 0;
	step = 0;
	size = ft_absolute_value(start - end);
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	if (start < end)
		step = 1;
	else
		step = -1;
	while (i < size)
	{
		tab[i] = start;
		start = start + step;
		i++;
	}
	return (tab);
}