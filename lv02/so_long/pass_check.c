/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:49 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/19 17:59:04 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(char **map, int y, int x)
{
	int	h;
	int	w;

	h = map_height(map);
	w = map_width(map);
	if (y < 0 || y >= h || x < 0 || x >= w)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	dfs(map, y - 1, x);
	dfs(map, y + 1, x);
	dfs(map, y, x - 1);
	dfs(map, y, x + 1);
}

static void	find_and_run_dfs(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				dfs(map, y, x);
				return ;
			}
			x++;
		}
		y++;
	}
}

static int	has_unreachable(char **m)
{
	int	y;
	int	x;

	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (m[y][x] == 'C' || m[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static void	free_map_copy(char **copy)
{
	int	y;

	if (!copy)
		return ;
	y = 0;
	while (copy[y])
	{
		free(copy[y]);
		y++;
	}
	free(copy);
}

int	check_valid_path(char **map, const char **errmsg)
{
	char	**copy;

	copy = duplicate_map(map);
	if (!copy)
	{
		if (errmsg)
			*errmsg = "Failed to copy map for path check.";
		return (0);
	}
	find_and_run_dfs(copy);
	if (has_unreachable(copy))
	{
		if (errmsg)
			*errmsg = "Unreachable collectible or exit";
		free_map_copy(copy);
		return (0);
	}
	free_map_copy(copy);
	return (1);
}
