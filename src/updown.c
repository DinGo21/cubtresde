/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updown.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:29:28 by disantam          #+#    #+#             */
/*   Updated: 2024/07/19 18:25:07 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_point	if_updown(t_mlx *data, t_point end, int x, float ang)
{
	if (end.x <= 0)
	{
		end.x = 0;
		end.y = data->player->y + catopo(data->player->x, ang);
		return (end);
	}
	if (x >= data->map->w_map - 1)
	{
		end.x = data->map->w_map * TILE_SIZE - TILE_SIZE;
		end.y = data->player->y - catopo(end.x - data->player->x, ang);
		return (end);
	}
	return (end);
}

t_point	dist_up(t_mlx *data, float py, float px, float ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;

	x = (px) / TILE_SIZE;
	auxy = py;
	y = (py - 1) / TILE_SIZE;
	while (auxy > y * TILE_SIZE)
		auxy--;
	end.y = py - fabs(py - auxy);
	end.x = catady(fabs(py - auxy), ang) + px;
	x = (end.x) / TILE_SIZE;
	y = (end.y) / TILE_SIZE;
	end.dir = 'U';
/* 	if (data->map[y][x] == '1')
		puts("es 1"); */
	if (end.x <= 0 || x >= data->map->w_map - 1)
		return (if_updown(data, end, x, ang));
	//if ((int)(end.x) % TILE_SIZE == 0 && (int)end.y % TILE_SIZE == 0 && ang > (PI / 2))
	{
		//if (data->map[y - 1][x - 1] == '1' && data->map[y][x -1] != '1')
			//return (end);
	}
	if (data->map->map2d[y - 1][x] != '1')
		return (dist_up(data, end.y , end.x, ang));
	return (end);
}

t_point	dist_down(t_mlx *data, float py, float px, float ang)
{
	int	x;
	int	auxy;
	int	y;
	t_point end;

	x = (px) / TILE_SIZE;
	auxy = py;
	y = (py) / TILE_SIZE;
	while (auxy < y * TILE_SIZE + TILE_SIZE)
		auxy++;
	end.x = catopo(auxy - py, ang - (M_PI / 2)) + px;
	end.y = py + auxy - py;
	x = (end.x) / TILE_SIZE;
	y = (end.y) / TILE_SIZE;
	end.dir = 'D';
	if (end.x <= 0 || x >= data->map->w_map - 1)
		return (if_updown(data, end, x, ang));
	if ((int)(end.x) % TILE_SIZE == 0 && (int)end.y % TILE_SIZE == 0 && ang > (M_PI / 2))
	{
		if (data->map->map2d[y][x] == '1')
			return (end);
	}
	if (data->map->map2d[y][x] != '1' && y < data->map->h_map)
		return (dist_down(data, end.y , end.x, ang));
	return (end);
}