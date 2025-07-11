/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:52:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/10 16:41:32 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**read_map(const char *filename)
{
	int		fd;
	int		lines;
	char	**map;
	char	*line;
	int		i;

	lines = count_lines(filename);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)))
	{
		map[i++] = ft_strtrim(line, "\n");
		free(line);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		ft_printf("Map is NULL!\n");
		return ;
	}
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}
void	init_map_size(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(game->map[0]); // 1行目の長さ
	while (game->map[height])
		height++;
	game->map_width = width;
	game->map_height = height;
}
int	map_width(char **map)
{
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	return (len);
}

int	map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
