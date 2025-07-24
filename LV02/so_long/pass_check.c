/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:19:49 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 11:11:21 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**duplicate_map(char **map)
{
	int		i;
	int		height;
	char	**copy;

	height = 0;
	while (map[height])
		height++;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	dfs(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	if (y > 0)
		dfs(map, y - 1, x);
	if (map[y + 1])
		dfs(map, y + 1, x);
	if (x > 0)
		dfs(map, y, x - 1);
	if (map[y][x + 1])
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

static void	check_unreachable(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
			{
				ft_printf("Error: No valid path to allcollectibles and exit\n");
				exit(1);
			}
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
}

void	check_valid_path(char **map)
{
	char	**copy;

	copy = duplicate_map(map);
	if (!copy)
		exit_error(NULL, "Error\nFailed to copy map for path check");
	find_and_run_dfs(copy);
	check_unreachable(copy);
}
