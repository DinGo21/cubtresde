/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:41:30 by disantam          #+#    #+#             */
/*   Updated: 2024/07/29 17:26:27 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	convert_rgb(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	return (r << 24 | g << 16 | b << 8 | 255 << 0);
}

int	get_pixel(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

void	draw_background(t_mlx *data, char **cc, char **ff)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y <= (S_HEIGHT) / 2)
	{
		x = -1;
		while (++x < S_WIDTH)
		{
			mlx_put_pixel(data->img, x, y, convert_rgb(cc));
		}
		y++;
	}
	while (y > (S_HEIGHT) / 2 && y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
		{
			mlx_put_pixel(data->img, x, y, convert_rgb(ff));
		}
		y++;
	}
}

void	draw2(t_mlx *data, t_ray *ray, mlx_texture_t *txtr)
{
	uint32_t	*pixels;
	double		tex_x;
	double		tex_y;
	double		step;

	pixels = (uint32_t *)txtr->pixels;
	if (ray->flag == 1)
		tex_x = fmodf((ray->h.y * (txtr->width / TILE_SIZE)),
				txtr->width);
	else
		tex_x = fmodf((ray->v.x * (txtr->width / TILE_SIZE)),
				txtr->width);
	step = 1.0 * txtr->height / ray->lineheight;
	tex_y = (ray->drawstart - S_HEIGHT / 2 + ray->lineheight
			/ 2) * step;
	while (ray->drawstart < ray->drawend)
	{
		mlx_put_pixel(data->img, data->x, ray->drawstart, get_pixel(
				pixels[(int)tex_y * txtr->width + (int)tex_x]));
		tex_y += step;
		ray->drawstart++;
	}
}

void	draw3d(t_mlx *data, t_ray *ray, float angle)
{
	t_point	*p;

	if (ray->flag == 0)
		p = &ray->v;
	else
		p = &ray->h;
	ray->distance *= cos(angle - data->player->angle);
	ray->lineheight = (TILE_SIZE / ray->distance) * ((S_WIDTH / 2)
			/ tan(data->player->fov / 2));
	ray->drawstart = S_HEIGHT / 2 - ray->lineheight / 2;
	ray->drawend = S_HEIGHT / 2 + ray->lineheight / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend > S_HEIGHT)
		ray->drawend = S_HEIGHT;
	if (p->dir == 'U')
		draw2(data, ray, data->textures[NO]);
	if (p->dir == 'D')
		draw2(data, ray, data->textures[SO]);
	if (p->dir == 'R')
		draw2(data, ray, data->textures[EA]);
	if (p->dir == 'L')
		draw2(data, ray, data->textures[WE]);
}
