#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int line_num;

	line_num = 1;
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: %s", line_num++, line);
		free(line);
	}
	close(fd);
	return (0);
}