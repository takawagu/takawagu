/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:56:36 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/23 16:05:28 by takawagu         ###   ########.fr       */
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
	if (!game->images.buffer.img)
		exit_error(game, "failed to create buffer image");
	game->images.buffer.addr = mlx_get_data_addr(game->images.buffer.img,
			&game->images.buffer.bpp, &game->images.buffer.line_length,
			&game->images.buffer.endian);
	if (!game->images.buffer.addr)
		exit_error(game, "failed to get buffer image address");
}

static void	load_xpm(t_game *game, t_image *img, char *path, char *desc)
{
	int	w;
	int	h;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img->img)
		exit_error(game, desc);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	if (!img->addr)
		exit_error(game, desc);
}

void	load_images(t_game *game)
{
	load_xpm(game, &game->images.wall, "textures/wall.xpm",
		"failed to load wall.xpm");
	load_xpm(game, &game->images.floor, "textures/floor.xpm",
		"failed to load floor.xpm");
	load_xpm(game, &game->images.player, "textures/player.xpm",
		"failed to load player.xpm");
	load_xpm(game, &game->images.collectible, "textures/collectible.xpm",
		"failed to load collectible.xpm");
	load_xpm(game, &game->images.enemy, "textures/enemy.xpm",
		"failed to load enemy.xpm");
	load_xpm(game, &game->images.exit, "textures/exit.xpm",
		"failed to load exit.xpm");
	init_buffer_image(game);
}
