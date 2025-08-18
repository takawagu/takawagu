/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:26:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 14:26:04 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_count	count_map_elements(char **map)
{
	t_count	cnt;

	cnt.p = 0;
	cnt.c = 0;
	cnt.e = 0;
	cnt.y = 0;
	while (map[cnt.y])
	{
		cnt.x = 0;
		while (map[cnt.y][cnt.x])
		{
			if (map[cnt.y][cnt.x] == 'P')
				cnt.p++;
			else if (map[cnt.y][cnt.x] == 'C')
				cnt.c++;
			else if (map[cnt.y][cnt.x] == 'E')
				cnt.e++;
			cnt.x++;
		}
		cnt.y++;
	}
	return (cnt);
}

void	validate_map_elements(t_count cnt, t_game *game)
{
	if (cnt.p != 1 || cnt.c < 1 || cnt.e != 1)
		exit_error(game, "Map must contain exactly 1 P and E, at least 1 C");
}

void	check_required_elements(char **map, t_game *game)
{
	t_count	cnt;

	cnt = count_map_elements(map);
	validate_map_elements(cnt, game);
}

void	validate_map(const char *filename, char **map, t_game *game)
{
	int	len;
	int	fd;

	if (!filename || !map)
		exit_error(game, "Invalid filename or map pointer.");
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		exit_error(game, "Map file must have .ber extension.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(game, "Failed to open map file.");
	close(fd);
	check_rectangular(map, game);
	check_horizontal_walls(map, game);
	check_vertical_walls(map, game);
	check_required_elements(map, game);
	check_valid_path(map);
}
