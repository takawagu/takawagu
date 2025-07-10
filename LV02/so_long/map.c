/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:52:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/09 18:14:23 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(const char *filename)
{
	int		fd;
	char	**map;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	map = NULL;
	count = 0;
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * 101);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[count++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	map[count] = NULL;
	close(fd);
	return (map);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
	{
		printf("Map is NULL!\n");
		return ;
	}
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
