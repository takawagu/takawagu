/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/05 12:34:23 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, game->images.floor.img, x
		* TILE_SIZE, y * TILE_SIZE);
	if (game->map_info.map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->images.wall.img, x
			* TILE_SIZE, y * TILE_SIZE);
		return ;
	}
	if (game->enemy.x == x && game->enemy.y == y)
		mlx_put_image_to_window(game->mlx, game->win, game->images.enemy.img, x
			* TILE_SIZE, y * TILE_SIZE);
	if (game->map_info.map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->images.collectible.img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map_info.map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->images.exit.img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (game->map_info.map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->images.player.img, x
			* TILE_SIZE, y * TILE_SIZE);
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
