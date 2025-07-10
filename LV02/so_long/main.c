/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:07:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/09 19:04:38 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_game	game;

	// MiniLibX 初期化
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 640, 480, "so_long");
	// マップ読み込み
	game.map = read_map("maps/testmap.ber");
	// 画像をロード
	load_images(&game);
	// 描画
	draw_map(&game);
	// フック登録 (構造体ポインタをそのまま渡す)
	mlx_key_hook(game.win, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	// イベントループ
	mlx_loop(game.mlx);
	return (0);
}
