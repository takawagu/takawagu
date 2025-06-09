#include <stddef.h> // For NULL || (void *)0 || 0

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	const char	*first_char_of_s_ptr;

	first_char_of_s_ptr = s;
	while (*s)
	{
		if (ft_strchr(reject, *s))
			break ;
		s++;
	}
	return (s - first_char_of_s_ptr);
}
