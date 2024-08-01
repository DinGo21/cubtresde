/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 01:58:30 by gpaez-ga          #+#    #+#             */
/*   Updated: 2024/08/01 06:21:30 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	coll(t_mlx *data, float ang, int ctr)
{
	int	dist;

	dist = 10;
	if ((data->map->map2d[(int)data->player->y / TILE_SIZE][((int)data->player->x + dist) / TILE_SIZE] == '1')
		&& (ang <= M_PI / 2 || ang >= M_PI + (M_PI / 2)) && ctr == 1)
		return (1);	 
	if (data->map->map2d[(int)data->player->y / TILE_SIZE][((int)data->player->x - dist) / TILE_SIZE] == '1'
		&& (ang >= M_PI / 2 && ang <= M_PI + (M_PI / 2)) && ctr == 1)
		return (1);
	if ((data->map->map2d[((int)data->player->y - dist) / TILE_SIZE][((int)data->player->x) / TILE_SIZE] == '1')
		&& ang >= 0 && ang <= M_PI && ctr == 2)
		return (2);
	if (data->map->map2d[((int)data->player->y + dist) / TILE_SIZE][((int)data->player->x) / TILE_SIZE] == '1'
		&& ang <= 2 * M_PI && ang >= M_PI  && ctr == 2)
		return (2);
	return (0);
}

void	cube(t_mlx *data,t_point max, int initx, int inity)
{
	int	y;
	int	c;

	y = 0;
	c = initx + max.x;
	while (initx < c)
	{

		mlx_put_pixel(data->mini, initx, inity, 0x000000ff);
		mlx_put_pixel(data->mini, initx, inity + max.y, 0x000000ff);
		initx++;
	}
	c = inity + max.y;
	while (inity <= c)
	{

		mlx_put_pixel(data->mini, initx - max.x, inity, 0x000000ff);
		mlx_put_pixel(data->mini, initx, inity, 0x000000ff);
		inity++;
	}
}

void	minimap(t_mlx *data)
{
	int	x;
	int	y;
	t_point mini;

	y = 0;
	mini.x = (S_WIDTH / 3) / data->map->w_map;
	mini.y = (S_HEIGHT / 3) / data->map->h_map;
	while (y < data->map->h_map)
	{
		x = 0;
		while (x < data->map->w_map)
		{
			if (data->map->map2d[y][x] == '1')
				cube(data, mini, x * mini.x, y * mini.y);
			x++;
		}
		y++;
	}
	int px = (data->player->x * (S_WIDTH / 3)) / S_WIDTH;
	int py = (data->player->y * (S_HEIGHT / 3)) / S_HEIGHT;
	cube(data, mini, data->map->plyr_x * mini.x, data->map->plyr_y * mini.y);
/* 	int auxx = data->player->x * (S_WIDTH / 3)  / S_WIDTH + mini.x + (mini.x / 2);
	int auxy = data->player->y * (S_WIDTH / 3)  / S_WIDTH + mini.y;
	mlx_put_pixel(data->mini, auxx, auxy, CRED); */
}
