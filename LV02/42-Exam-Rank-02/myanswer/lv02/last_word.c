#include <string.h>
#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = NULL;

	while (*s)
	{
		if (*s == (char)c)
			last = s;
		s++;
	}
	return ((char *)last);
}

void	print_last_word(char *str)
{
	char	*last_space;
	char	*word;

	// 末尾からスペース or タブ を探す
	last_space = strrchr(str, ' ');
	if (!last_space)
		last_space = strrchr(str, '\t');
	if (last_space)
		word = last_space + 1;
	else
		word = str;
	// スペース・タブ・NULL まで出力
	while (*word && *word != ' ' && *word != '\t')
	{
		write(1, word, 1);
		word++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
