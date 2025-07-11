/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:07:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/10 17:05:42 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
	int move_timer; // フレームカウンタ
}			t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_collectible;
	void	*img_enemy;
	char	**map;
	int		tile_size;

	int		player_x;
	int		player_y;
	int		map_width;
	int		map_height;
	int		collectibles;
	t_enemy	enemy;
	int		move_count;
}			t_game;

# define TILE_SIZE 64

int			handle_key(int keycode, t_game *game);
int			close_window(t_game *game);

char		**read_map(const char *filename);
void		print_map(char **map);

void		load_images(t_game *game);
void		draw_map(t_game *game);
void		init_map_size(t_game *game);

void		init_player(t_game *game);
void		move_player(t_game *game, int dx, int dy);

void		init_enemy(t_game *game);
void		update_enemy(t_game *game);
int			game_loop(t_game *game);

int			map_width(char **map);
int			map_height(char **map);

# define ESC_KEY 65307
# define KEY_W 119
# define KEY_W_UPPER 87
# define KEY_A 97
# define KEY_A_UPPER 65
# define KEY_S 115
# define KEY_S_UPPER 83
# define KEY_D 100
# define KEY_D_UPPER 68

#endif