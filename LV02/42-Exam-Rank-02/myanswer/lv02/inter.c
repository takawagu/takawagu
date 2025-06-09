#include <unistd.h>

int	main(int argc, char **argv)
{
	char			*s1;
	char			*s2;
	char			seen[256] = {0};
	unsigned char	c;

	int i, j;
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	s1 = argv[1];
	s2 = argv[2];
	// s2 の文字をマーク
	j = 0;
	while (s2[j])
	{
		seen[(unsigned char)s2[j]] = 1;
		j++;
	}
	// s1 を順にチェック
	i = 0;
	while (s1[i])
	{
		c = (unsigned char)s1[i];
		if (seen[c])
		{
			write(1, &c, 1);
			seen[c] = 0; // 二重出力を防ぐ
		}
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
