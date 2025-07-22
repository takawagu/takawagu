/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:18:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/22 14:47:19 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_buffer_image(t_game *game)
{
	int	w;
	int	h;

	w = TILE_SIZE * map_width(game->map_info.map);
	h = TILE_SIZE * map_height(game->map_info.map);
	game->images.buffer.img = mlx_new_image(game->mlx, w, h);
	game->images.buffer.addr = mlx_get_data_addr(game->images.buffer.img,
			&game->images.buffer.bpp, &game->images.buffer.line_length,
			&game->images.buffer.endian);
}

void	load_images(t_game *game)
{
	int	w;
	int	h;

	game->images.wall.img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	if (!game->images.wall.img)
		exit_error(game, "failed to load wall.xpm");
	game->images.wall.addr = mlx_get_data_addr(game->images.wall.img,
			&game->images.wall.bpp, &game->images.wall.line_length,
			&game->images.wall.endian);
	if (!game->images.wall.addr)
		exit_error(game, "failed to get addr of wall image");
	game->images.floor.img = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	if (!game->images.floor.img)
		exit_error(game, "failed to load floor.xpm");
	game->images.floor.addr = mlx_get_data_addr(game->images.floor.img,
			&game->images.floor.bpp, &game->images.floor.line_length,
			&game->images.floor.endian);
	if (!game->images.floor.addr)
		exit_error(game, "failed to get addr of floor image");
	game->images.player.img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &w, &h);
	if (!game->images.player.img)
		exit_error(game, "failed to load player.xpm");
	game->images.player.addr = mlx_get_data_addr(game->images.player.img,
			&game->images.player.bpp, &game->images.player.line_length,
			&game->images.player.endian);
	if (!game->images.player.addr)
		exit_error(game, "failed to get addr of player image");
	game->images.collectible.img = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	if (!game->images.collectible.img)
		exit_error(game, "failed to load collectible.xpm");
	game->images.collectible.addr = mlx_get_data_addr(game->images.collectible.img,
			&game->images.collectible.bpp,
			&game->images.collectible.line_length,
			&game->images.collectible.endian);
	if (!game->images.collectible.addr)
		exit_error(game, "failed to get addr of collectible image");
	game->images.enemy.img = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &w, &h);
	if (!game->images.enemy.img)
		exit_error(game, "failed to load enemy.xpm");
	game->images.enemy.addr = mlx_get_data_addr(game->images.enemy.img,
			&game->images.enemy.bpp, &game->images.enemy.line_length,
			&game->images.enemy.endian);
	if (!game->images.enemy.addr)
		exit_error(game, "failed to get addr of enemy image");
	game->images.exit.img = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	if (!game->images.exit.img)
		exit_error(game, "failed to load exit.xpm");
	game->images.exit.addr = mlx_get_data_addr(game->images.exit.img,
			&game->images.exit.bpp, &game->images.exit.line_length,
			&game->images.exit.endian);
	if (!game->images.exit.addr)
		exit_error(game, "failed to get addr of exit image");
	init_buffer_image(game);
}

void	copy_texture_to_buffer(t_game *game, t_image *src, int dst_x, int dst_y)
{
	int	tex_offset;
	int	dst_offset;

	int x, y;
	for (y = 0; y < TILE_SIZE; y++)
	{
		for (x = 0; x < TILE_SIZE; x++)
		{
			tex_offset = y * src->line_length + x * (src->bpp / 8);
			dst_offset = (dst_y + y) * game->images.buffer.line_length + (dst_x
					+ x) * (game->images.buffer.bpp / 8);
			*(unsigned int *)(game->images.buffer.addr
					+ dst_offset) = *(unsigned int *)(src->addr + tex_offset);
		}
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
