/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:36:24 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/22 15:38:05 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		ft_printf("Map is NULL!\n");
		return ;
	}
	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	init_map_size(t_game *game)
{
	int	width;
	int	height;

	height = 0;
	width = ft_strlen(game->map_info.map[0]);
	while (game->map_info.map[height])
		height++;
	game->map_info.width = width;
	game->map_info.height = height;
}
