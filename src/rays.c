/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:23:31 by disantam          #+#    #+#             */
/*   Updated: 2024/07/23 18:37:18 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	get_color(mlx_image_t *img, int p)
// {
// 	int	c;

// 	c = img->pixels[p] << 24 | img->pixels[p + 1] << 16 | img->pixels[p + 2]
// 		<< 8 | img->pixels[p + 3];
// 	return (c);
// }
/*  void	drawtexture(t_map *data, t_point init, t_point end, t_point p, float aux)
 {
	float i;
	int pixel;
	float	multi;
	int	x;

	x = (int)p.x / TILE_SIZE;
	pixel = ((TILE_SIZE * TILE_SIZE) - TILE_SIZE + ((int)p.x % TILE_SIZE)) * 4;
	multi = (end.y - init.y) / TILE_SIZE;
	i = i + (multi / (int)multi);
	while (S_HEIGHT / 2 > init.y)
	{
		//i = multi - (multi / (int)multi);
		i =  -1;
		while (i < multi - (multi / (int)multi))
		{
			if (init.y + i >= 0 && init.y < S_HEIGHT / 2)
				mlx_put_pixel(data->image.aux, init.x, (int)init.y + i, get_color(data->image.wall, pixel));
			i = i + (multi / (int)multi);
		}
		pixel = pixel - (TILE_SIZE * 4);
		init.y = init.y + i;
	}
	init.y = S_HEIGHT / 2;
	pixel = ((TILE_SIZE * TILE_SIZE) - TILE_SIZE + ((int)p.x % TILE_SIZE)) * 4;
	while (end.y >= init.y)
	{
		//i = multi - (multi / (int)multi);
		i =  -1;
		while (i < multi - (multi / (int)multi))
		{
			if (init.y + i >= 0 && init.y < S_HEIGHT)
				mlx_put_pixel(data->image.aux, init.x, (int)init.y + i, get_color(data->image.wall, pixel));
			i = i + (multi / (int)multi);
		}
		pixel = pixel - (TILE_SIZE * 4);
		init.y = init.y + i;
	}
 } */

/* int	drawpart(t_map *data, t_point init, t_point end, t_point p, float aux)
{
	
} */

/* void	drawtexture(t_mlx *data, t_point init, t_point end, t_point p, float aux)
{
		float i;
		int pixel;
		float	multi;
		pixel = ((TILE_SIZE * TILE_SIZE) - TILE_SIZE + ((int)p.x % TILE_SIZE)) * 4;
		multi = (end.y - init.y) / TILE_SIZE;
		//if (aux == S_WIDTH / 2)
			//printf("end - init / TILE_SIZE = %f\n", (end.y - init.y) / TILE_SIZE);
		while (end.y >= init.y)
		{
			i =  0;
			while (i <= (ceil)(multi) && init.y + i <= end.y)
			{
				if (init.y + i >= 0 && init.y < S_HEIGHT)
					mlx_put_pixel(data->img, init.x, (int)(init.y  + i), get_color(data->textures[0], pixel));
				//if (aux == S_WIDTH / 2 && get_color(data->image.wall, pixel) == 0 && init.y < S_HEIGHT)
				//	printf("color %d en y %f\n", get_color(data->image.wall, pixel), init.y);
				i++;
			}
			if (init.y >= 0 && init.y < S_HEIGHT && init.y + i <= end.y)
				mlx_put_pixel(data->img, init.x, (int)(init.y + i + 1), get_color(data->textures[0], pixel));
			i = 0;
			while (i < (ceil)(multi) && init.y + i <= end.y)
				i = i + (multi / (ceil)(multi));
			// if ((init.y + i) > (int)init.y + (int)i + 1 && init.y + 1 >= 0 && init.y + 1 < S_HEIGHT)
			// 	printf("se salta\n");
			init.y = (init.y) + (i);
			// if (init.y - 1 >= 0 && init.y - 1 < S_HEIGHT)
			// 	mlx_put_pixel(data->image.aux, init.x, (int)(init.y - 1), get_color(data->image.wall, pixel));
			pixel = pixel - (TILE_SIZE * 4);
		}
} */

// void	draw3d(t_mlx *data, t_point p, float aux)
// {
// 	t_player init;
// 	t_point end;
// 	float	dist_adap;
// 	int	alt_adap;

// 	//dist_adap = catady(S_WIDTH / 2, 62 / 2) - data->player->y;	//CAMBIAR
// 	//dist_adap = catady(S_WIDTH / 2, FOW / 2) - data->player->pp.y;	//CAMBIAR
// 	dist_adap = catady(S_HEIGHT / 2, FOV / 2);
// 	alt_adap = (100 / p.h) * dist_adap;		//CAMBIAR
// 	init.y = S_HEIGHT / 2 + alt_adap / 2;
// 	init.x = aux;
// 	end.y = S_HEIGHT / 2 - alt_adap / 2;
// 	end.x =  aux;

//  	if (init.y >= S_HEIGHT)
// 		init.y = S_HEIGHT - 1;
// 	if (init.y <= 0)
// 		init.y = 0;
// 	if (end.y <= 0)
// 		end.y = 0;
// 	if (end.y >= S_HEIGHT)
// 		end.y = S_HEIGHT - 1;
// 	if (p.dir == 'U')
// 		draw(data, end, &init, CWHI);
// 	if (p.dir == 'D')
// 		draw(data, end, &init, CCIA);
// 	if (p.dir == 'R')
// 		draw(data, end, &init, CRED);
// 	if (p.dir == 'L')
// 		draw(data, end, &init, CGRN);
// 	// drawtexture(data, init, end, p, aux);
// }

// void	deletepix(t_mlx *data)
// {
// 	int	i;
// 	int	k;

// 	i = 0;
// 	k = 0;
// 	while (i < S_HEIGHT)
// 	{
// 		k = 0;
// 		while (k < S_WIDTH)
// 		{
// 			mlx_put_pixel(data->img, k, i, 0x00000000);
// 			k++;
// 		}
// 		i++;
// 	}
// }

void	draw_background(t_mlx *data)
{
	int x = 0;
	int y = 0;

	while (y <= (S_HEIGHT) / 2)
	{
		x = -1;
		while (++x < S_WIDTH)
			mlx_put_pixel(data->img, x, y, 0x6cffebFF);
		y++;
	}
	while (y > (S_HEIGHT) / 2 && y < S_HEIGHT)
	{
		x = -1;
		while (++x < S_WIDTH)
			mlx_put_pixel(data->img, x, y, 0x13DA1FFF);
		y++;
	}
}

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

void draw2(t_mlx *data, int drawstart, int drawend, int color)
{
	while (drawstart < drawend)
	{
		mlx_put_pixel(data->img, data->x, drawstart, color);
		drawstart++;
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

void	draw3d(t_mlx *data, t_point p, int ray, float angle)
{
	int		drawstart;
	int		drawend;
	int		lineheight;

	p.h *= cos(angle - data->player->angle);
	lineheight = (TILE_SIZE / p.h) * ((S_WIDTH / 2) / 
		tan(data->player->fov / 2));
	drawstart = S_HEIGHT / 2 - lineheight / 2;
	drawend = S_HEIGHT / 2 + lineheight / 2;
	data->x = ray;
	if (drawstart < 0)
		drawstart = 0;
	if (drawend > S_HEIGHT)
		drawend = S_HEIGHT;
	if (p.dir == 'U')
		draw2(data, drawstart, drawend, CWHI);
	if (p.dir == 'D')
		draw2(data, drawstart, drawend, CCIA);
	if (p.dir == 'R')
		draw2(data, drawstart, drawend, CRED);
	if (p.dir == 'L')
		draw2(data, drawstart, drawend, CGRN);
}

void	choose_line(t_mlx *data, float ang, int ray)
{
	t_point	v;
	t_point	h;
	float	py;
	float	px;

	py = data->player->y;
	px = data->player->x;
	h.dir = 'A';
	v.dir = 'A';
	if ((ang >= 0 && ang <= (M_PI / 2)) || (ang > M_PI + (M_PI / 2) && ang < 2 * M_PI))
		h = dist_right(data, py, px, ang);
	if (ang > (M_PI / 2) && ang <= M_PI + (M_PI / 2))
		h = dist_left(data, py, px, ang);
	if (ang > 0 && ang < M_PI)	
		v = dist_up(data, py, px, ang);
	if (ang >= M_PI && ang < 2 * M_PI)
		v = dist_down(data, py, px, ang);
	h.h = hipo(data->player->y - h.y, data->player->x - h.x);
	v.h = hipo(data->player->y - v.y, data->player->x - v.x);
	if (v.h < h.h)
		h = v;
	draw3d(data, h, ray, ang);
	// drawlines(data, h);
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
	draw_background(data);
	while (rays <= S_WIDTH)
	{
		if (ang >= 2 * M_PI)
			ang = ang - (2 * M_PI);
		if (ang < 0)
			ang = (2 * M_PI) + ang;
		choose_line(data, ang, rays);
		ang = ang - totang;
		count = count - totang;
		rays = rays + 1;
	}
}
