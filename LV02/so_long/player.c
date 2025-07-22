/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:24:50 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/16 19:39:53 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	game->map_info.collectibles = 0;
	while (game->map_info.map[y])
	{
		x = 0;
		while (game->map_info.map[y][x])
		{
			if (game->map_info.map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			else if (game->map_info.map[y][x] == 'C')
			{
				game->map_info.collectibles++;
			}
			x++;
		}
		y++;
	}
	game->move_count = 0;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (new_x < 0 || new_y < 0 || !game->map_info.map[new_y]
		|| !game->map_info.map[new_y][new_x])
		return ;
	if (game->map_info.map[new_y][new_x] == '1')
		return ;
	if (game->map_info.map[new_y][new_x] == 'C')
		game->map_info.collectibles--;
	if (game->map_info.map[new_y][new_x] == 'E'
		&& game->map_info.collectibles == 0)
	{
		ft_printf("Congratulations! You cleared the game!\n");
		exit(0);
	}
	game->map_info.map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map_info.map[new_y][new_x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	draw_map(game);
}
