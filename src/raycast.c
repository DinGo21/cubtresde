/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:34:35 by disantam          #+#    #+#             */
/*   Updated: 2024/07/22 17:57:33 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	inter_check(float angle, double *inter, double *step, int is_hor)
// {
// 	if (is_hor)
// 	{
// 		if (angle > 0 && angle < M_PI)
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	else
// 	{
// 		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
// 		{
// 			*inter += TILE_SIZE;
// 			return (-1);
// 		}
// 		*step *= -1;
// 	}
// 	return (1);
// }

// static int	wall_hit(float x, float y, t_map *map)
// {
// 	int	map_x;
// 	int	map_y;

// 	if (x < 0 || y < 0)
// 		return (0);
// 	map_x = floor(x / TILE_SIZE);
// 	map_y = floor(y / TILE_SIZE);
// 	if ((map_y >= map->h_map || map_x >= map->w_map))
// 		return (0);
// 	if (map->map2d[map_y] && map_x <= 
// 		(int)ft_strlen(map->map2d[map_y]))
// 	{
// 		if (map->map2d[map_y][map_x] == '1')
// 			return (0);
// 	}
// 	return (1);
// }

// static float	get_h(t_mlx *data, t_player *ply, t_ray *ray, float angle)
// {
// 	double	step_x;
// 	double	step_y;
// 	int		pixel;

// 	step_y = TILE_SIZE;
// 	step_x = TILE_SIZE / tan(angle);
// 	ray->h_y = floor(ply->y / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angle, &ray->h_y, &step_y, 1);
// 	ray->h_x = ply->x + (ray->h_y - ply->y) / tan(angle);
// 	if ((unit_circle(angle, 'y') && step_x > 0) || 
// 		(!unit_circle(angle, 'y') && step_x < 0))
// 	{
// 		step_x *= -1;
// 	}
// 	while (wall_hit(ray->h_x, ray->h_y - pixel, data->map))
// 	{
// 		ray->h_x += step_x;
// 		ray->h_y += step_y;
// 	}
// 	return (sqrt(pow(ray->h_x - ply->x, 2) + 
// 		pow(ray->h_y - ply->y, 2)));
// }

// static float	get_v(t_mlx *data, t_player *ply, t_ray *ray, float angle)
// {
// 	double	step_x;
// 	double	step_y;
// 	int		pixel;

// 	step_x = TILE_SIZE; 
// 	step_y = TILE_SIZE * tan(angle);
// 	ray->v_x = floor(ply->x / TILE_SIZE) * TILE_SIZE;
// 	pixel = inter_check(angle, &ray->v_x, &step_x, 0); 
// 	ray->v_y = ply->y + (ray->v_x - ply->x) * tan(angle);
// 	if ((unit_circle(angle, 'x') && step_y < 0) || 
// 		(!unit_circle(angle, 'x') && step_y > 0))
// 	{
// 		step_y *= -1;
// 	}
// 	while (wall_hit(ray->v_x - pixel, ray->v_y, data->map))
// 	{
// 		ray->v_x += step_x;
// 		ray->v_y += step_y;
// 	}
// 	return (sqrt(pow(ray->v_x - ply->x, 2) + 
// 		pow(ray->v_y - ply->y, 2)));
// }

// void	raycast(t_mlx *data, t_ray *ray, t_player *player)
// {
// 	double	h_inter;
// 	double	v_inter;
// 	int		x;

// 	x = 0;
// 	ray->angle = player->angle - (player->fov / 2);
// 	while (x < S_WIDTH)
// 	{
// 		ray->flag = 0;
// 		h_inter = get_h(data, player, ray,
// 			normalize_angle(ray->angle));
// 		v_inter = get_v(data, player, ray, 
// 			normalize_angle(ray->angle));
// 		if (v_inter <= h_inter)
// 			ray->distance = v_inter;
// 		else
// 		{
// 			ray->distance = h_inter;
// 			ray->flag = 1;
// 		}
// 		render_wall(data, player, ray, x);
// 		x++;
// 		ray->angle += (player->fov / S_WIDTH);
// 	}
// }

void	get_lineheight(t_ray *ray, t_player *player)
{
	ray->lineheight = (int)(S_HEIGHT / ray->wall_dist);
	ray->drawstart = (-ray->lineheight / 2) + (S_HEIGHT / 2);	
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = (ray->lineheight / 2) + (S_HEIGHT / 2);
	if (ray->drawend >= S_HEIGHT)
		ray->drawend = S_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->y + ray->wall_dist * ray->raydir_y;
	else
		ray->wall_x = player->x + ray->wall_dist * ray->raydir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_wall_dist(t_mlx *data, t_ray *ray, t_player *player)
{
	while (1)
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map->map2d[ray->map_y][ray->map_x] == '1')
			break ;
	}
	if (ray->side == 0)
		ray->wall_dist = (ray->map_x - player->x + 
			(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->wall_dist = (ray->map_y - player->y + 
			(1 - ray->step_y) / 2) / ray->raydir_y;
}

void	get_sidedist(t_ray *ray, t_player *player)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (player->x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_x = (ray->map_x + 1.0 - player->x) * ray->delta_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (player->y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_y = (ray->map_y + 1.0 - player->y) * ray->delta_y;
	}
}

void	init_ray(t_ray *ray, t_player *player, int x)
{
	ray->camera_x = 2 * x / (double) S_WIDTH - 1;
	ray->raydir_x = player->dir_x + player->plan_x * ray->camera_x;
	ray->raydir_y = player->dir_y + player->plan_y * ray->camera_x;
	ray->delta_x = fabs(1 / ray->raydir_x);
	ray->delta_y = fabs(1 / ray->raydir_y);
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
}

void	raycast(t_mlx *data, t_ray *ray, t_player *player)
{
	int		x;

	x = -1;
	while (++x < S_WIDTH)
	{
		init_ray(ray, player, x);
		get_sidedist(ray, player);
		get_wall_dist(data, ray, player);
		get_lineheight(ray, player);
		draw_wall(data, ray, x);
	}
}
