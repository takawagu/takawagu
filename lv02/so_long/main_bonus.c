/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:36:53 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 12:30:20 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_loop_bonus(t_game *game)
{
	update_enemy(game);
	draw_map(game);
	return (0);
}

void	run_game_loop(t_game *game)
{
	draw_map(game);
	mlx_loop_hook(game->mlx, game_loop_bonus, game);
	mlx_key_hook(game->win, handle_key, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
	exit_game(game);
}

static void	check_args(int argc, char **argv, t_game *game)
{
	if (argc < 2)
	{
		ft_printf("Usage: ./so_long <map.ber>\n");
		exit(EXIT_FAILURE);
	}
	check_map_file_name(argv[1], game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_args(argc, argv, &game);
	init_game_bonus(&game, argv[1]);
	create_window(&game);
	run_game_loop(&game);
	return (0);
}
