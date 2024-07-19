/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:21:38 by disantam          #+#    #+#             */
/*   Updated: 2024/07/15 12:51:20 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_position(t_map *map, char **map2d, int y, int x)
{
	if (isplayer(map2d[y][x]) && map->plyr_x != 0)
	{
		return (ft_error("multiple players"), -1);
	}
	if (isplayer(map2d[y][x]) && map->plyr_x == 0)
	{
		map->plyr_x = x;
		map->plyr_y = y;
	}
	if (map2d[y][x] == '0' || isplayer(map2d[y][x]))
	{
		if (map2d[y][x + 1] == ' ' || map2d[y][x - 1] == ' '
			|| map2d[y + 1][x] == ' ' || map2d[y - 1][x] == ' ')
		{
			return (ft_error("invalid map"), -1);
		}
	}
	return (0);
}

static void	check_line(t_mlx *data, t_map *map, char **map2d, int y)
{
	int	x;

	x = 1;
	if (!ft_strchr(" 1", map2d[y][0]))
	{
		mlx_error(data, "invalid map");
	}
	while (map2d[y][x + 1] != '\0')
	{
		if (!ft_strchr(" 01NSEW", map2d[y][x]))
		{
			mlx_error(data, "invalid character");
		}
		if (check_position(map, map2d, y, x) < 0)
		{
			mlx_error(data, NULL);
		}
		x++;
	}
	if (!ft_strchr(" 1", map2d[y][x]))
	{
		mlx_error(data, "invalid map");
	}
}

void	check_map(t_mlx *data, t_map *map)
{
	int	y;
	int	x;
	
	x = 0;
	while (map->map2d[0][x] == ' ' || map->map2d[0][x] == '1')
		x++;
	if (map->map2d[0][x] != '\0')
	{
		mlx_error(data, "invalid map");
	}
	y = 0;
	while (map->map2d[++y + 1] != NULL)
	{
		check_line(data, map, map->map2d, y);
	}
	x = 0;
	while (map->map2d[y][x] == ' ' || map->map2d[y][x] == '1')
		x++;
	if (map->map2d[y][x] != '\0')
	{
		mlx_error(data, "invalid map");
	}
}
