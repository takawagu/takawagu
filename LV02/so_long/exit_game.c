/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:54:11 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 11:24:24 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_error(t_game *game, const char *msg)
{
	if (game)
		cleanup_game(game);
	ft_printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}

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
	if (game->images.floor.img)
		mlx_destroy_image(game->mlx, game->images.floor.img);
	if (game->images.wall.img)
		mlx_destroy_image(game->mlx, game->images.wall.img);
	if (game->images.collectible.img)
		mlx_destroy_image(game->mlx, game->images.collectible.img);
	if (game->images.player.img)
		mlx_destroy_image(game->mlx, game->images.player.img);
	if (game->images.enemy.img)
		mlx_destroy_image(game->mlx, game->images.enemy.img);
	if (game->images.exit.img)
		mlx_destroy_image(game->mlx, game->images.exit.img);
	if (game->images.buffer.img)
		mlx_destroy_image(game->mlx, game->images.buffer.img);
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
