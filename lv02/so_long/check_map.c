/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:26:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 16:12:17 by takawagu         ###   ########.fr       */
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

int	validate_map_elements(t_count cnt, const char **errmsg)
{
	if (cnt.p != 1 || cnt.c < 1 || cnt.e != 1)
	{
		if (errmsg)
			*errmsg = "Map must contain exactly 1 P and 1 E, and at least 1 C";
		return (0);
	}
	return (1);
}

int	check_required_elements(char **map, const char **errmsg)
{
	t_count	cnt;

	if (!map || !map[0])
	{
		if (errmsg)
			*errmsg = "Empty map";
		return (0);
	}
	cnt = count_map_elements(map);
	return (validate_map_elements(cnt, errmsg));
}

int	validate_map_path(const char *filename, const char **errmsg)
{
	int	len;
	int	fd;

	if (!filename)
	{
		if (errmsg)
			*errmsg = "Invalid filename.";
		return (0);
	}
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		if (errmsg)
			*errmsg = "Map file must have .ber extension.";
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		if (errmsg)
			*errmsg = "Failed to open map file.";
		return (0);
	}
	close(fd);
	return (1);
}

int	validate_map_layout(char **map, const char **errmsg)
{
	if (!map)
	{
		if (errmsg)
			*errmsg = "Invalid map pointer.";
		return (0);
	}
	if (!check_rectangular(map, errmsg))
		return (0);
	if (!check_horizontal_walls(map, errmsg))
		return (0);
	if (!check_vertical_walls(map, errmsg))
		return (0);
	if (!check_required_elements(map, errmsg))
		return (0);
	if (!check_valid_path(map, errmsg))
		return (0);
	return (1);
}
