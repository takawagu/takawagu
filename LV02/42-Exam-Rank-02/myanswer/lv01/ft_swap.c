#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int a;
	int b;

	a = 1;
	b = 2;

	ft_swap(&a, &b);

	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}