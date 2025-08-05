/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:56:36 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/05 12:35:03 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
