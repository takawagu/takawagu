#include <stdio.h>
#include <stdlib.h>

int	gcd(int a, int b)
{
	int	temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a > 0 && b > 0)
			printf("%d\n", gcd(a, b));
		else
			printf("\n"); // 正の整数じゃなかったら改行
	}
	else
	{
		printf("\n");
	}
	return (0);
}
