#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	while ('\t' <= *str && *str <= '\r' || *str == ' ')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -(sign);
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && (('0' <= *str && *str <= '9')))
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return ((int)(n * sign));
}

int	main(void)
{
	char *str;
	int n;

	str = "-2147483648";
	n = ft_atoi(str);
	printf("%d\n", n);
	return (0);
}