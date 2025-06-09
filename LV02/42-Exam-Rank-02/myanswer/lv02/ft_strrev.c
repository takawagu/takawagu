#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	unsigned int	start;
	unsigned int	end;
	char			temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "HELLO";
	printf("%s\n", ft_strrev(str));
	return (0);
}