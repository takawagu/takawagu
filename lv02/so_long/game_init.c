/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:23:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 17:32:14 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_file_name(const char *filename, t_game *game)
{
	int	len;
	int	fd;

	if (!filename)
		exit_error(game, "No filename provided.");
	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		exit_error(game, "Map file must have .ber extension.");
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(game, "Map file does not exist or cannot be opened.");
	close(fd);
}

void	init_game(t_game *g, const char *map_path)
{
	const char	*errmsg = NULL;

	g->map_info.map = read_map(map_path);
	if (!g->map_info.map)
		exit_error(g, "Failed to load map.");
	init_map_size(g);
	if (!validate_map_path(map_path, &errmsg)
		|| !validate_map_layout(g->map_info.map, &errmsg))
		exit_error(g, "Invalid map.");
	init_player(g);
	g->mlx = mlx_init();
	if (!g->mlx)
		exit_error(g, "mlx_init failed.");
	load_images(g);
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
