/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:42:28 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/23 16:25:57 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_game(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->images.wall.img)
		mlx_destroy_image(game->mlx, game->images.wall.img);
	if (game->images.floor.img)
		mlx_destroy_image(game->mlx, game->images.floor.img);
	if (game->images.player.img)
		mlx_destroy_image(game->mlx, game->images.player.img);
	if (game->images.collectible.img)
		mlx_destroy_image(game->mlx, game->images.collectible.img);
	if (game->images.enemy.img)
		mlx_destroy_image(game->mlx, game->images.enemy.img);
	if (game->images.exit.img)
		mlx_destroy_image(game->mlx, game->images.exit.img);
	if (game->images.buffer.img)
		mlx_destroy_image(game->mlx, game->images.buffer.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map_info.map);
}
