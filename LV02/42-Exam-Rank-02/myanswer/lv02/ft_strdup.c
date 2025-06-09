#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	len = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char) * len + 1);
	if (!cpy)
		return (NULL);
	while (src[i] != '\0')
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	main(void)
{
	char *str = "mpaoddojsd";
	printf("%s\n", ft_strdup(str));
	return (0);
}