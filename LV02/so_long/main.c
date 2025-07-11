/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:07:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/10 16:44:23 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop(t_game *game)
{
	update_enemy(game);
	draw_map(game);
	return (0);
}

int	main(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.map = read_map("maps/testmap.ber");
	init_player(&game);
	init_enemy(&game);
	load_images(&game);
	game.win = mlx_new_window(game.mlx, TILE_SIZE * map_width(game.map),
			TILE_SIZE * map_height(game.map), "so_long");
	draw_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
