#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
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

void	rcapitalize(char *str)
{
	int	i;

	i = 0;
	char prev = ' '; // 前の文字が空白かどうか判定用
	while (str[i])
	{
		// 単語の途中 → 最後の文字を探す
		if (is_alpha(str[i]))
		{
			if (!is_alpha(str[i + 1]) || str[i + 1] == '\0')
				to_upper(&str[i]);
			else
				to_lower(&str[i]);
		}
		write(1, &str[i], 1);
		i++;
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
			rcapitalize(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
