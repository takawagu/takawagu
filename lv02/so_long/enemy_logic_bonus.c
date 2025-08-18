/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_logic_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:23:35 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/15 18:36:13 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_enemy(t_game *game, int new_x, int new_y)
{
	game->map_info.map[game->enemy.y][game->enemy.x] = game->enemy.under_tile;
	game->enemy.under_tile = game->map_info.map[new_y][new_x];
	game->enemy.x = new_x;
	game->enemy.y = new_y;
	game->map_info.map[new_y][new_x] = 'X';
}

void	game_over(t_game *game)
{
	if (game->enemy.x == game->player_x && game->enemy.y == game->player_y)
	{
		ft_printf("%s\n", "You were caught by Piccolo!");
		exit_game(game);
	}
}

void	choose_random_enemy_direction(t_game *game)
{
	int	dir;

	dir = rand() % 4;
	if (dir == 0)
	{
		game->enemy.dir_x = 1;
		game->enemy.dir_y = 0;
	}
	else if (dir == 1)
	{
		game->enemy.dir_x = -1;
		game->enemy.dir_y = 0;
	}
	else if (dir == 2)
	{
		game->enemy.dir_x = 0;
		game->enemy.dir_y = 1;
	}
	else
	{
		game->enemy.dir_x = 0;
		game->enemy.dir_y = -1;
	}
}

void	try_move_enemy(t_game *game)
{
	int	new_x;
	int	new_y;
	int	tries;

	new_x = 0;
	new_y = 0;
	tries = 0;
	if (rand() % 5 == 0)
		choose_random_enemy_direction(game);
	new_x = game->enemy.x + game->enemy.dir_x;
	new_y = game->enemy.y + game->enemy.dir_y;
	if (!can_move_enemy(game, new_x, new_y))
	{
		while (tries < 4)
		{
			choose_random_enemy_direction(game);
			new_x = game->enemy.x + game->enemy.dir_x;
			new_y = game->enemy.y + game->enemy.dir_y;
			if (can_move_enemy(game, new_x, new_y))
				break ;
			tries++;
		}
	}
	if (can_move_enemy(game, new_x, new_y))
		move_enemy(game, new_x, new_y);
}

void	update_enemy(t_game *game)
{
	game->enemy.move_timer++;
	if (game->enemy.move_timer < 40)
		return ;
	game->enemy.move_timer = 0;
	try_move_enemy(game);
	game_over(game);
}
