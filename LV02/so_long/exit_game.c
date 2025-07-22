/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:54:11 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/16 19:38:40 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	destroy_images(t_game *game)
{
	if (game->images.floor)
		mlx_destroy_image(game->mlx, game->images.floor);
	if (game->images.wall)
		mlx_destroy_image(game->mlx, game->images.wall);
	if (game->images.collectible)
		mlx_destroy_image(game->mlx, game->images.collectible);
	if (game->images.player)
		mlx_destroy_image(game->mlx, game->images.player);
	if (game->images.enemy)
		mlx_destroy_image(game->mlx, game->images.enemy);
	if (game->images.exit)
		mlx_destroy_image(game->mlx, game->images.exit);
	if (game->images.buffer)
		mlx_destroy_image(game->mlx, game->images.buffer);
}

void	exit_game(t_game *game)
{
	if (!game)
		exit(1);
	if (game->mlx)
	{
		destroy_images(game);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map_info.map);
	exit(0);
}
