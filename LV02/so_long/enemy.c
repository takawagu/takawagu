/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:23:35 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/10 17:22:41 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemy(t_game *game)
{
	int	y;
	int	x;
	int	found;

	found = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X')
			{
				game->enemy.x = x;
				game->enemy.y = y;
				game->enemy.dir_x = 1; // 右へ
				game->enemy.dir_y = 0; // 垂直には動かない
				found = 1;
			}
			x++;
		}
		y++;
	}
	if (!found)
	{
		ft_printf("Error: Enemy (X) not found in the map.\n");
		exit(1);
	}
}

void	update_enemy(t_game *game)
{
	int	tries;
	int	dir;

	int new_x, new_y;
	tries = 0;
	game->enemy.move_timer++;
	if (game->enemy.move_timer < 20)
		return ;
	game->enemy.move_timer = 0;
	new_x = game->enemy.x + game->enemy.dir_x;
	new_y = game->enemy.y + game->enemy.dir_y;
	if (game->map[new_y][new_x] == '1')
	{
		while (tries < 4)
		{
			dir = rand() % 4;
			if (dir == 0)
			{
				game->enemy.dir_x = 1;
				game->enemy.dir_y = 0;
			}
			else if (dir == 1)
			{
				game->enemy.dir_x = -1;
				game->enemy.dir_y = 0;
			}
			else if (dir == 2)
			{
				game->enemy.dir_x = 0;
				game->enemy.dir_y = 1;
			}
			else
			{
				game->enemy.dir_x = 0;
				game->enemy.dir_y = -1;
			}
			new_x = game->enemy.x + game->enemy.dir_x;
			new_y = game->enemy.y + game->enemy.dir_y;
			if (game->map[new_y][new_x] == '0'
				|| game->map[new_y][new_x] == 'P')
				break ;
			tries++;
		}
		if (tries == 4)
			return ;
	}
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'P')
	{
		game->map[game->enemy.y][game->enemy.x] = '0';
		game->enemy.x = new_x;
		game->enemy.y = new_y;
		game->map[game->enemy.y][game->enemy.x] = 'X';
	}
	if (game->enemy.x == game->player_x && game->enemy.y == game->player_y)
	{
		ft_printf("GAME OVER! You were caught by Freeza!\n");
		exit(0);
	}
}
