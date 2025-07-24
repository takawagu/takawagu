/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 10:32:46 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_texture_to_buffer(t_game *game, t_image *src, int dst_x, int dst_y)
{
	int	x;
	int	y;
	int	tex_offset;
	int	dst_offset;

	if (!src || !src->addr || !game->images.buffer.addr)
		return ;
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			tex_offset = y * src->line_length + x * (src->bpp / 8);
			dst_offset = (dst_y + y) * game->images.buffer.line_length + (dst_x
					+ x) * (game->images.buffer.bpp / 8);
			*(unsigned int *)(game->images.buffer.addr
					+ dst_offset) = *(unsigned int *)(src->addr + tex_offset);
			x++;
		}
		y++;
	}
}

void	draw_tile(t_game *game, int x, int y)
{
	copy_texture_to_buffer(game, &game->images.floor, x * TILE_SIZE, y
		* TILE_SIZE);
	if (game->map_info.map[y][x] == '1')
	{
		copy_texture_to_buffer(game, &game->images.wall, x * TILE_SIZE, y
			* TILE_SIZE);
		return ;
	}
	if (game->enemy.x == x && game->enemy.y == y)
	{
		copy_texture_to_buffer(game, &game->images.enemy, x * TILE_SIZE, y
			* TILE_SIZE);
	}
	if (game->map_info.map[y][x] == 'C')
		copy_texture_to_buffer(game, &game->images.collectible, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map_info.map[y][x] == 'E')
		copy_texture_to_buffer(game, &game->images.exit, x * TILE_SIZE, y
			* TILE_SIZE);
	else if (game->map_info.map[y][x] == 'P')
		copy_texture_to_buffer(game, &game->images.player, x * TILE_SIZE, y
			* TILE_SIZE);
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
	mlx_put_image_to_window(game->mlx, game->win, game->images.buffer.img, 0,
		0);
}
