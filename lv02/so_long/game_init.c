/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:23:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/05 12:34:06 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file_name(const char *filename, t_game *game)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		exit_error(game, "Map file must have .ber extension");
}

void	init_game(t_game *game, char *map_path)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(NULL, "mlx_init failed.");
	game->map_info.map = read_map(map_path);
	if (!game->map_info.map)
		exit_error(game, "Failed to load map.");
	validate_map(map_path, game->map_info.map, game);
	init_player(game);
	load_images(game);
}

void	create_window(t_game *game)
{
	int	width;
	int	height;

	width = TILE_SIZE * map_width(game->map_info.map);
	height = TILE_SIZE * map_height(game->map_info.map);
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (!game->win)
		exit_error(game, "Failed to create window.");
}
