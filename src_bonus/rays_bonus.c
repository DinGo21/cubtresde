/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:23:31 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 04:21:56 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	draw(t_mlx *data, t_point end, t_player *begin, int color)
{
	float	delta_x;
	float	delta_y;
	float	pixel_x;
	float	pixel_y;
	int		pixels;

	delta_x = end.x - begin->x;
	delta_y = end.y - begin->y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	pixel_x = begin->x;
	pixel_y = begin->y;
	while (pixels > 0)
	{
		mlx_put_pixel(data->img, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	drawlines(t_mlx *data, t_point h)
{
	if (h.dir == 'U')
		draw(data, h, data->player, CBLK);
	if (h.dir == 'D')
		draw(data, h, data->player, CCIA);
	if (h.dir == 'R')
		draw(data, h, data->player, CRED);
	if (h.dir == 'L')
		draw(data, h, data->player, CGRN);
}

void	choose_line(t_mlx *data, t_player *player, float ang)
{
	t_ray	ray;
	float	v_inter;
	float	h_inter;

	ray.flag = 0;
	if ((ang >= 0 && ang <= (M_PI / 2)) || (ang > M_PI
			+ (M_PI / 2) && ang < 2 * M_PI))
		ray.h = dist_right(data, player->y, player->x, ang);
	if (ang > (M_PI / 2) && ang <= M_PI + (M_PI / 2))
		ray.h = dist_left(data, player->y, player->x, ang);
	if (ang > 0 && ang < M_PI)
		ray.v = dist_up(data, player->y, player->x, ang);
	if (ang >= M_PI && ang < 2 * M_PI)
		ray.v = dist_down(data, player->y, player->x, ang);
	h_inter = hipo(player->y - ray.h.y, player->x - ray.h.x);
	v_inter = hipo(player->y - ray.v.y, player->x - ray.v.x);
	if (v_inter < h_inter)
	{
		ray.distance = v_inter;
		//drawlines(data,ray.v);
	}
	else
	{
		ray.distance = h_inter;
		ray.flag = 1;
		//drawlines(data,ray.h);
	}
	draw3d(data, &ray, ang);
}

void	drawang(t_mlx *data)
{
	float	ang;
	float	count;
	float	totang;
	int		rays;

	rays = 0;
	ang = data->player->angle + (data->player->fov / 2);
	count = data->player->angle + (data->player->fov / 2);
	totang = data->player->fov / S_WIDTH;
	draw_background(data, data->map->cc, data->map->ff);
	minimap(data);
	while (rays < S_WIDTH)
	{
		if (ang >= 2 * M_PI)
			ang = ang - (2 * M_PI);
		if (ang < 0)
			ang = (2 * M_PI) + ang;
		data->x = rays;
		choose_line(data, data->player, ang);
		ang = ang - totang;
		count = count - totang;
		rays++;
	}
}
