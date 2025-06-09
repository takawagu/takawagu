#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	to_upper(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - ('a' - 'A');
}

void	to_lower(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = *c + ('a' - 'A');
}

void	capitalize(char *str)
{
	int	new_word;

	new_word = 1;
	while (*str)
	{
		if (is_space(*str))
			new_word = 1;
		else if (new_word)
		{
			to_upper(str);
			new_word = 0;
		}
		else
		{
			to_lower(str);
		}
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		while (i < argc)
		{
			capitalize(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
