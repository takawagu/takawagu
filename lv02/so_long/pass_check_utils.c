/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_check_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:23:46 by takawagu          #+#    #+#             */
/*   Updated: 2025/08/18 20:46:52 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

static int	copy_rows(char **copy, char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (0);
		}
		i++;
	}
	copy[height] = NULL;
	return (1);
}

char	**duplicate_map(char **map)
{
	int		height;
	char	**copy;

	if (!map)
		return (NULL);
	height = get_map_height(map);
	copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	if (!copy_rows(copy, map, height))
		return (NULL);
	return (copy);
}
