/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/19 14:27:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	while(改行がくるまで)
	{
	bytes_read = read(fd, buf, 100);  //（入力先、格納したいアドレス、バッファサイズ）
	出力？

	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_num;

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
