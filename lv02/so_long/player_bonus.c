/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:51:30 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 15:49:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map_info.collectibles = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			if (game->map_info.map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->player_under = '0';
			}
			else if (game->map_info.map[y][x] == 'C')
			{
				game->map_info.collectibles++;
			}
			x++;
		}
		y++;
	}
	game->move_count = 0;
}

static int	is_valid_move(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || !game->map_info.map[y] || !game->map_info.map[y][x])
		return (0);
	if (game->map_info.map[y][x] == '1')
		return (0);
	return (1);
}

static void	handle_tile_effect(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map_info.map[y][x];
	if (game->enemy_enabled && tile == 'X')
	{
		game_over(game);
		exit_game(game);
	}
	else if (tile == 'C')
	{
		game->map_info.collectibles--;
		game->map_info.map[y][x] = '0';
	}
	else if (tile == 'E' && game->map_info.collectibles == 0)
	{
		ft_printf("Congratulations! You cleared the game!\n");
		exit_game(game);
	}
}

static void	update_player_position(t_game *game, int new_x, int new_y)
{
	char	tile_after_effect;

	tile_after_effect = game->map_info.map[new_y][new_x];
	game->map_info.map[game->player_y][game->player_x] = game->player_under;
	if (tile_after_effect == 'E')
		game->player_under = 'E';
	else
		game->player_under = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map_info.map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	draw_map(game);
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (!is_valid_move(game, new_x, new_y))
		return ;
	handle_tile_effect(game, new_x, new_y);
	update_player_position(game, new_x, new_y);
}
