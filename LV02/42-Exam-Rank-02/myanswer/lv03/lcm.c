unsigned int	gcd(unsigned int a, unsigned int b)
{
	unsigned int	temp;

	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / gcd(a, b)) * b);
}
#include <stdio.h>

int	main(void)
{
	printf("lcm(5, 10) = %u\n", lcm(5, 10)); // → 10
	printf("lcm(6, 8) = %u\n", lcm(6, 8));   // → 24
	printf("lcm(21, 6) = %u\n", lcm(21, 6)); // → 42
	printf("lcm(0, 10) = %u\n", lcm(0, 10)); // → 0
	printf("lcm(7, 3) = %u\n", lcm(7, 3));   // → 21
	return (0);
}
