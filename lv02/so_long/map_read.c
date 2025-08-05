/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:52:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/05 13:16:15 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_size(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(game->map_info.map[0]);
	while (game->map_info.map[height])
		height++;
	game->map_info.width = width;
	game->map_info.height = height;
}

static int	count_lines(const char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	fill_map_array(int fd, char **map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while ((line))
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (i);
}

char	**read_map(const char *filename)
{
	int		fd;
	int		lines;
	char	**map;

	lines = count_lines(filename);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	if (!fill_map_array(fd, map))
	{
		close(fd);
		free_map(map);
		return (NULL);
	}
	close(fd);
	return (map);
}
