#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	result;
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	result = s1[i] - s2[i];
	return (result);
}

int	main(void)
{
	char *s1;
	char *s2;

	s1 = "aaaa";
	s2 = "abaa";

	printf("%d\n", ft_strcmp(s1, s2));

	return (0);
}