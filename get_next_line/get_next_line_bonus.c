/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/05 16:07:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*strjoin_and_free(char *stash, char *buf)
{
	char	*joined;

	if (!stash)
		return (ft_strdup(buf));
	joined = ft_strjoin(stash, buf);
	free(stash);
	return (joined);
}

char	*extract_line(char *stash)
{
	char	*line;
	char	*newline_ptr;
	size_t	line_len;
	size_t	i;

	i = 0;
	newline_ptr = ft_strchr(stash, '\n');
	if (newline_ptr == NULL)
		line_len = ft_strlen(stash);
	else
		line_len = (size_t)(newline_ptr - stash + 1);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	while (i < line_len)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stash(char *stash)
{
	char	*newline_ptr;
	char	*new_stash;
	size_t	len;

	if (!stash)
		return (NULL);
	newline_ptr = ft_strchr(stash, '\n');
	if (!newline_ptr)
		return (free(stash), NULL);
	newline_ptr++;
	if (*newline_ptr == '\0')
		return (free(stash), NULL);
	len = ft_strlen(newline_ptr);
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	ft_memcpy(new_stash, newline_ptr, len);
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes_read;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (free(buf), NULL);
	while (stash && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buf), free(stash), NULL);
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		stash = strjoin_and_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > __INT_MAX__)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd] || *stash[fd] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;
// 	int		line_num;

// 	line_num = 1;
// 	if (argc != 2)
// 	{
// 		printf("Usage: %s <filename>\n", argv[0]);
// 		return (1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("Line %d: %s", line_num++, line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	while (1)
	{
		line1 = get_next_line(fd1);
		if (!line1)
			break ;
		printf("fd1: %s\n", line1);
		free(line1);
		line2 = get_next_line(fd2);
		if (!line2)
			break ;
		printf("fd2: %s\n", line2);
		free(line2);
	}
	close(fd1);
	close(fd2);
	return (0);
}
