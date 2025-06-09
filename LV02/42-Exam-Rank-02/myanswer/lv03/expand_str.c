#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	i = 0;
	first = 1;
	if (argc == 2)
	{
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i])
		{
			if (argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				first = 0;
			}
			else if (!first && (argv[1][i + 1] != ' ' && argv[1][i + 1] != '\t'
					&& argv[1][i + 1] != '\0'))
			{
				write(1, "   ", 3);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
