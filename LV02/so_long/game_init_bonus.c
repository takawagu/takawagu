/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:35:49 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/23 16:36:06 by takawagu         ###   ########.fr       */
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

void	check_map_file_name(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Map file must have .ber extension\n");
		exit(1);
	}
}
void	init_game_bonus(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(NULL, "mlx_init failed.");
	game->map_info.map = read_map(map_path);
	if (!game->map_info.map)
		exit_error(game, "Failed to load map.");
	validate_map(map_path, game->map_info.map);
	init_player(game);
	init_enemy(game);
	load_images(game);
}

void	create_window(t_game *game)
{
	int width;
	int height;

	width = TILE_SIZE * map_width(game->map_info.map);
	height = TILE_SIZE * map_height(game->map_info.map);
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		exit_error(game, "Failed to create window.");
}