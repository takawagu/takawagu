/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:40:23 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 11:27:18 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangular(char **map, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != len)
			exit_error(game, "Map is not rectangular");
		i++;
	}
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

void	check_horizontal_walls(char **map, t_game *game)
{
	int	width;
	int	x;

	width = ft_strlen(map[0]);
	x = 0;
	while (x < width)
	{
		if (map[0][x] != '1' || map[map_height(map) - 1][x] != '1')
			exit_error(game, "Map must be surrounded by horizontal walls");
		x++;
	}
}

void	check_vertical_walls(char **map, t_game *game)
{
	int	width;
	int	height;
	int	y;

	width = ft_strlen(map[0]);
	height = map_height(map);
	y = 0;
	while (y < height)
	{
		if (map[y][0] != '1' || map[y][width - 1] != '1')
			exit_error(game, "Map must be surrounded by vertical walls");
		y++;
	}
}
