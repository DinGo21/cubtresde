/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftright.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:28:29 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 11:44:51 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	if_leftright(t_mlx *data, t_point end, float ang)
{
	if (end.y <= 0)
	{
		end.y = 0;
		end.x = data->player->x + catady(data->player->y, ang);
		return (end);
	}
	if (end.y > data->map->h_map * TILE_SIZE)
	{
		end.y = data->map->h_map * TILE_SIZE;
		end.x = data->player->x - catady(end.y - data->player->y, ang);
		return (end);
	}
	return (end);
}

t_point	dist_right(t_mlx *data, float py, float px, float ang)
{
	int		x;
	int		y;
	int		auxx;
	t_point	end;

	end.h = 0;
	x = px / TILE_SIZE;
	auxx = px;
	y = py / TILE_SIZE;
	while (auxx < x * TILE_SIZE + TILE_SIZE)
		auxx++;
	end.x = fabs(px - auxx) + px;
	end.y = py - catopo(fabs(px - auxx), ang);
	end.dir = 'R';
	if (end.y <= 0 || end.y > data->map->h_map * TILE_SIZE)
		return (if_leftright(data, end, ang));
	y = end.y / TILE_SIZE;
	if (x < data->map->w_map && data->map->map2d[y][x + 1] != '1')
		return (dist_right(data, end.y, end.x, ang));
	return (end);
}

t_point	dist_left(t_mlx *data, float py, float px, float ang)
{
	int		x;
	int		y;
	int		auxx;
	t_point	end;

	end.h = 0;
	x = (px - 1) / TILE_SIZE;
	auxx = px;
	y = py / TILE_SIZE;
	while (auxx > x * TILE_SIZE)
		auxx--;
	end.x = px - fabs(px - auxx);
	end.y = py + catopo(fabs(px - auxx), ang);
	end.dir = 'L';
	if (end.y <= 0 || end.y > data->map->h_map * TILE_SIZE)
		return (if_leftright(data, end, ang));
	x = end.x / TILE_SIZE;
	y = end.y / TILE_SIZE;
	if (x > 0 && data->map->map2d[y][x - 1] != '1')
		return (dist_left(data, end.y, end.x, ang));
	return (end);
}
