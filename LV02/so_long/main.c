/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:07:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/22 14:53:16 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

void	exit_error(t_game *game, const char *message)
{
	ft_printf("Error: %s\n", message);
	if (game)
		exit_game(game);
	else
		exit(1);
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

void	run_game_loop(t_game *game)
{
	draw_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	exit_game(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		return (1);
	}
	check_map_file_name(argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		exit_error(NULL, "mlx_init failed.");
	game.map_info.map = read_map(argv[1]);
	if (!game.map_info.map)
		exit_error(&game, "Failed to load map.");
	validate_map(argv[1], game.map_info.map);
	init_player(&game);
	init_buffer_image(&game);
	load_images(&game);
	game.win = mlx_new_window(game.mlx, TILE_SIZE
			* map_width(game.map_info.map), TILE_SIZE
			* map_height(game.map_info.map), "so_long");
	if (!game.win)
		exit_error(&game, "Failed to create window.");
	run_game_loop(&game);
	return (0);
}
