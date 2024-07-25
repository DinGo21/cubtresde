/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:23:31 by disantam          #+#    #+#             */
/*   Updated: 2024/07/25 14:44:00 by disantam         ###   ########.fr       */
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
	if ((ang >= 0 && ang <= (M_PI / 2)) || (ang > M_PI + (M_PI / 2) && ang < 2 * M_PI))
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
		ray.distance = v_inter;
	else
	{
		ray.distance = h_inter;
		ray.flag = 1;
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
	while (rays <= S_WIDTH)
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
