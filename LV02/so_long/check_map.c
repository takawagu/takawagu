/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:26:03 by takawagu          #+#    #+#             */
/*   Updated: 2025/07/22 15:23:31 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_count	count_map_elements(char **map)
{
	t_count	cnt;

	cnt.p = 0;
	cnt.c = 0;
	cnt.e = 0;
	cnt.y = 0;
	while (map[cnt.y])
	{
		cnt.x = 0;
		while (map[cnt.y][cnt.x])
		{
			if (map[cnt.y][cnt.x] == 'P')
				cnt.p++;
			else if (map[cnt.y][cnt.x] == 'C')
				cnt.c++;
			else if (map[cnt.y][cnt.x] == 'E')
				cnt.e++;
			cnt.x++;
		}
		cnt.y++;
	}
	return (cnt);
}

void	validate_map_elements(t_count cnt)
{
	if (cnt.p != 1 || cnt.c < 1 || cnt.e < 1)
	{
		ft_printf("Error: Map must contain 1 P, >=1 C, >=1 E\n");
		exit(1);
	}
}

void	check_required_elements(char **map)
{
	t_count	cnt;

	cnt = count_map_elements(map);
	validate_map_elements(cnt);
}

void	validate_map(const char *filename, char **map)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error: Map file must have .ber extension\n");
		exit(1);
	}
	check_rectangular(map);
	check_horizontal_walls(map);
	check_vertical_walls(map);
	check_required_elements(map);
	check_valid_path(map);
}
