/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/10 16:35:13 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 画像読み込み & 描画ループ
#include "so_long.h"

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w,
			&h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm", &w,
			&h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &w,
			&h);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x
				* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
					* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectible, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player,
					x * TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'X')
				mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x
					* TILE_SIZE, y * TILE_SIZE);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x
					* TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
