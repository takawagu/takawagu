/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:40:23 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 17:59:50 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rectangular(char **map, const char **errmsg)
{
	int	i;
	int	w;

	i = 0;
	if (!map || !map[0])
	{
		if (errmsg)
			*errmsg = "Empty map.";
		return (0);
	}
	w = (int)ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != w)
		{
			if (errmsg)
				*errmsg = "Map is not rectangular.";
			return (0);
		}
		i++;
	}
	return (1);
}

static int	prepare_map_dims(char **map, int *w, int *h, const char **errmsg)
{
	if (!map || !map[0])
	{
		if (errmsg)
			*errmsg = "Empty map.";
		return (0);
	}
	if (w)
		*w = map_width(map);
	if (h)
		*h = map_height(map);
	if ((w && *w == 0) || (h && *h == 0))
	{
		if (errmsg)
			*errmsg = "Invalid map size.";
		return (0);
	}
	return (1);
}

int	check_horizontal_walls(char **map, const char **errmsg)
{
	int	x;
	int	w;
	int	h;

	if (!prepare_map_dims(map, &w, &h, errmsg))
		return (0);
	x = 0;
	while (x < w)
	{
		if (map[0][x] != '1' || map[h - 1][x] != '1')
		{
			if (errmsg)
				*errmsg = "Map must be surrounded by horizontal walls.";
			return (0);
		}
		x++;
	}
	return (1);
}

int	check_vertical_walls(char **map, const char **errmsg)
{
	int	y;
	int	w;
	int	h;

	if (!prepare_map_dims(map, &w, &h, errmsg))
		return (0);
	y = 0;
	while (y < h)
	{
		if (map[y][0] != '1' || map[y][w - 1] != '1')
		{
			if (errmsg)
				*errmsg = "Map must be surrounded by vertical walls.";
			return (0);
		}
		y++;
	}
	return (1);
}
