#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	main(void)
{
	char	*str;

	str = "Hello";
	printf("%d\n", ft_strlen(str));
	return (0);
}
