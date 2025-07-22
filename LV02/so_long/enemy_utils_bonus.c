/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:11:38 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/16 19:42:55 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_and_set_enemy(t_game *game, int x, int y)
{
	if (game->map_info.map[y][x] == 'X')
	{
		game->enemy.x = x;
		game->enemy.y = y;
		game->enemy.dir_x = 1;
		game->enemy.dir_y = 0;
		game->enemy.move_timer = 0;
		game->enemy.under_tile = '0';
		return (1);
	}
	return (0);
}

void	init_enemy(t_game *game)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			found |= check_and_set_enemy(game, x, y);
			x++;
		}
		y++;
	}
	if (!found)
	{
		ft_printf("Error: Enemy (X) not found in the map.\n");
		exit(1);
	}
}

int	try_change_enemy_direction(t_game *game)
{
	int	tries;
	int	new_x;
	int	new_y;

	tries = 0;
	while (tries < 4)
	{
		choose_random_enemy_direction(game);
		new_x = game->enemy.x + game->enemy.dir_x;
		new_y = game->enemy.y + game->enemy.dir_y;
		if (can_move_enemy(game, new_x, new_y))
			return (1);
		tries++;
	}
	return (0);
}

int	can_move_enemy(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map_info.map[y][x];
	return (tile == '0' || tile == 'P' || tile == 'C' || tile == 'E');
}

void	handle_enemy_direction(t_game *game)
{
	if (game->map_info.map[game->enemy.y + game->enemy.dir_y][game->enemy.x
		+ game->enemy.dir_x] == '1')
		try_change_enemy_direction(game);
}
