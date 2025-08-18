/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/15 18:23:25 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map_info.map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->images.wall.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->images.floor.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->enemy.x == x && game->enemy.y == y)
		mlx_put_image_to_window(game->mlx, game->win, game->images.enemy.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.collectible.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->images.exit.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->images.player.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		exit_error(game, "Unknown tile type in map.");
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}
