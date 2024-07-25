/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:41:30 by disantam          #+#    #+#             */
/*   Updated: 2024/07/25 14:44:08 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	render_wall(t_mlx *data, t_ray *ray, int x)
// {
// 	int			color;
// 	int			dir;
// 	int			texture_x;
// 	double		pos;
// 	double		step;
// 	int			width;
// 	int	*arr;

// 	dir = get_color(ray);
// 	arr = (int *)data->textures[dir]->pixels;
// 	width = data->textures[dir]->width;
// 	texture_x = (int)(ray->wall_x * width);
// 	if ((ray->side == 0 && ray->raydir_x < 0) || (ray->side == 1 &&
// 		ray->raydir_y > 0))
// 		texture_x = width - texture_x - 1;
// 	step = 1.0 * data->textures[dir]->height / ray->lineheight;
// 	pos = (ray->drawstart - S_HEIGHT / 2 + ray->lineheight / 
// 		2) * step;
// 	draw_floor_ceiling(data, ray, x);
// 	while (ray->drawstart < ray->drawend)
// 	{
// 		pos += step;
// 		color = arr[width * ((int)pos & (width - 
// 			1)) + texture_x];
// 		mlx_put_pixel(data->img, x, ray->drawstart, 
// 			convert_color(color));
// 		ray->drawstart++;
// 	}
// }

// mlx_texture_t	*get_texture(t_mlx *data, t_ray *ray)
// {
// 	if (ray->flag == 0)
// 	{
// 		if (ray->angle > M_PI / 2 && ray->angle < 3 * (M_PI / 2))
// 			return (data->textures[EA]);
// 		else
// 			return (data->textures[WE]);
// 	}
// 	else
// 	{
// 		if (ray->angle > 0 && ray->angle < M_PI)
// 			return (data->textures[SO]);
// 		else
// 			return (data->textures[NO]);
// 	}
// }

// void	draw_wall(t_mlx *data, t_ray *ray, int x)
// {
// 	double			tex_x;
// 	double			tex_y;
// 	double			step;
// 	int				*arr;
// 	mlx_texture_t	*txtr;

// 	txtr = get_texture(data, ray);
// 	arr = (int *)txtr->pixels;
// 	if (ray->flag == 1)
// 		tex_x = fmodf((ray->h.x * (txtr->width / TILE_SIZE)),
// 			txtr->width);
// 	else
// 		tex_x = fmodf((ray->v.y * (txtr->width / TILE_SIZE)),
// 			txtr->width);
// 	step = 1.0 * txtr->height / ray->lineheight;
// 	tex_y = (ray->drawstart - S_HEIGHT / 2 + ray->lineheight / 
// 		2) * step;
// 	draw_floor_ceiling(data, ray, x);
// 	while (ray->drawstart < ray->drawend)
// 	{
// 		mlx_put_pixel(data->img, x, ray->drawstart, 
// 			get_pixel(arr[(int)tex_y * txtr->width + (int)tex_x]));
// 		tex_y += step;
// 		ray->drawstart++;
// 	}
// }

// void	render_wall(t_mlx *data, t_player *ply, t_ray *ray, int x)
// {
// 	ray->distance *= cos(normalize_angle(ray->angle - ply->angle));
// 	ray->lineheight = (TILE_SIZE / ray->distance) * ((S_WIDTH / 2) /
// 	tan(ply->fov / 2));
// 	ray->drawstart = (S_HEIGHT / 2) - (ray->lineheight / 2);
// 	ray->drawend = (S_HEIGHT / 2) + (ray->lineheight / 2);
// 	if (ray->drawstart < 0)
// 		ray->drawstart = 0;
// 	if (ray->drawend > S_HEIGHT)
// 		ray->drawend = S_HEIGHT;
// 	draw_wall(data, ray, x);
// }

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
	int x;
	int y;

	x = 0;
	y = 0;
	while (y <= (S_HEIGHT) / 2)
	{
		x = -1;
		while (++x < S_WIDTH)
			mlx_put_pixel(data->img, x, y, convert_rgb(cc));
		y++;
	}
	while (y > (S_HEIGHT) / 2 && y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
			mlx_put_pixel(data->img, x, y, convert_rgb(ff));
		y++;
	}
}

void draw2(t_mlx *data, t_ray *ray, mlx_texture_t *txtr)
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
	tex_y = (ray->drawstart - S_HEIGHT / 2 + ray->lineheight / 
		2) * step;
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
	ray->lineheight = (TILE_SIZE / ray->distance) * ((S_WIDTH / 2) / 
		tan(data->player->fov / 2));
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
