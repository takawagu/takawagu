/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:07:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/24 12:22:10 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_enemy
{
	int			x;
	int			y;
	int			dir_x;
	int			dir_y;
	char		under_tile;
	int			move_timer;
}				t_enemy;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_images
{
	t_image		wall;
	t_image		floor;
	t_image		player;
	t_image		collectible;
	t_image		enemy;
	t_image		exit;
	t_image		buffer;
}				t_images;

typedef struct s_map_info
{
	char		**map;
	int			width;
	int			height;
	int			tile_size;
	int			collectibles;
}				t_map_info;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	int			move_count;
	t_images	images;
	t_map_info	map_info;
	t_enemy		enemy;

}				t_game;

typedef struct s_count
{
	int			p;
	int			c;
	int			e;
	int			y;
	int			x;
}				t_count;

# define TILE_SIZE 64
# define ESC_KEY 65307
# define KEY_W 119
# define KEY_W_UPPER 87
# define KEY_A 97
# define KEY_A_UPPER 65
# define KEY_S 115
# define KEY_S_UPPER 83
# define KEY_D 100
# define KEY_D_UPPER 68

void			check_rectangular(char **map, t_game *game);
int				map_width(char **map);
int				map_height(char **map);
void			check_horizontal_walls(char **map, t_game *game);
void			check_vertical_walls(char **map, t_game *game);

t_count			count_map_elements(char **map);
void			validate_map_elements(t_count count, t_game *game);
void			check_required_elements(char **map, t_game *game);
void			validate_map(const char *filename, char **map, t_game *game);

void			exit_error(t_game *game, const char *message);
void			free_map(char **map);
void			destroy_images(t_game *game);
void			exit_game(t_game *game);

int				handle_key(int keycode, t_game *game);
int				close_window(t_game *game);

void			init_buffer_image(t_game *game);
void			load_images(t_game *game);

int				game_loop(t_game *game);
void			run_game_loop(t_game *game);

char			**read_map(const char *filename);

void			print_map(char **map);
void			init_map_size(t_game *game);

void			check_valid_path(char **map);

void			init_player(t_game *game);
void			move_player(t_game *game, int dx, int dy);

void			copy_texture_to_buffer(t_game *game, t_image *src, int dst_x,
					int dst_y);
void			draw_tile(t_game *game, int x, int y);
void			draw_map(t_game *game);

void			check_map_file_name(const char *filename, t_game *game);

void			exit_error(t_game *game, const char *msg);
void			init_game(t_game *game, char *map_path);
void			create_window(t_game *game);

// bonus
void			cleanup_game(t_game *game);
void			check_player_collision(t_game *game);
void			choose_random_enemy_direction(t_game *game);
void			try_move_enemy(t_game *game);
void			update_enemy(t_game *game);
void			move_enemy(t_game *game, int new_x, int new_y);

int				check_and_set_enemy(t_game *game, int x, int y);
void			init_enemy(t_game *game);
int				try_change_enemy_direction(t_game *game);
int				can_move_enemy(t_game *game, int x, int y);
void			handle_enemy_direction(t_game *game);

void			init_game_bonus(t_game *game, char *map_path);

#endif