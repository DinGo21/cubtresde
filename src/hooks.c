/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:49 by disantam          #+#    #+#             */
/*   Updated: 2024/07/31 03:14:14 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	key_release(mlx_key_data_t keydata, t_mlx *data)
{
	if (keydata.key == MLX_KEY_LEFT && (keydata.action
			== MLX_RELEASE))
		data->player->rot = 0;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action
			== MLX_RELEASE))
		data->player->rot = 0;
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_RELEASE))
		data->player->u_d = 0;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_RELEASE))
		data->player->u_d = 0;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_RELEASE))
		data->player->l_r = 0;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_RELEASE))
		data->player->l_r = 0;
}

void	key_hooks(mlx_key_data_t keydata, void *param)
{
	t_mlx	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && (keydata.action
			== MLX_PRESS))
	{
		mlx_close_window(data->mlx);
	}
	if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS))
		data->player->u_d = 1;
	if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS))
		data->player->u_d = -1;
	if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS))
		data->player->l_r = -1;
	if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS))
		data->player->l_r = 1;
	if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS))
		data->player->rot = -1;
	if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS))
		data->player->rot = 1;
	key_release(keydata, data);
}

void	rotate(t_mlx *data, int rot)
{
	if (rot == -1)
	{
		data->player->angle += ROTATION_SPEED;
		if (data->player->angle > 2 * M_PI)
		{
			data->player->angle -= 2 * M_PI;
		}
	}
	else
	{
		data->player->angle -= ROTATION_SPEED;
		if (data->player->angle < 0)
		{
			data->player->angle += 2 * M_PI;
		}
	}
}

void	move(t_point end, t_player *begin)
{
	float	delta_x;
	float	delta_y;
	int		pixels;
	int		spd;

	//No va exactamente a la mitad?
	if (begin->u_d == 1 && (begin->l_r == 1 || begin->l_r == -1))
		spd = PLAYER_SPEED / 2;
	else if (begin->u_d == -1 && (begin->l_r == 1 || begin->l_r == -1))
		spd = PLAYER_SPEED / 2;
	else
		spd = PLAYER_SPEED;
	delta_x = end.x - begin->x;
	delta_y = end.y - begin->y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
		begin->x += delta_x * spd;
		begin->y += delta_y * spd;
	//printf("x %f y %f\n", begin->x, begin->y);
	//printf("delta x %f delta y %f\n", delta_x, delta_y);
}

void	choose_mov(t_mlx *data, t_player *player, float ang)
{
	t_ray	ray;
	float	v_inter;
	float	h_inter;

	ray.flag = 0;
	if (ang >= 2 * M_PI)
		ang = ang - (2 * M_PI);
	if (ang < 0)
		ang = (2 * M_PI) + ang;
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
		move(ray.v, data->player);
	}
	else
	{
		ray.distance = h_inter;
		ray.flag = 1;
		move(ray.h, data->player);
		//drawlines(data,ray.h);
	}
	//printf("px %f py %f\n", data->player->x, data->player->y);
}

/* void	move(t_mlx *data, char **map, float move_x, float move_y)
{
	int	grid_x;
	int	grid_y;
	int	new_x;
	int	new_y;

	new_x = roundf(data->player->x + move_x);
	new_y = roundf(data->player->y + move_y);
	grid_x = new_x / TILE_SIZE;
	grid_y = new_y / TILE_SIZE;
	if (map[grid_y][grid_x] != '1' &&
		map[grid_y][data->player->x / TILE_SIZE] != '1' &&
		map[data->player->y / TILE_SIZE][grid_x] != '1')
	{
		data->player->x = new_x;
		data->player->y = new_y;
	}
} */

void	hooks(t_mlx *data)
{
	if (data->player->rot == 1)
		rotate(data, data->player->rot);
	if (data->player->rot == -1)
		rotate(data, data->player->rot);
/* 	if (data->player->l_r == -1)
	{
		move_x = -sin(data->player->angle) * PLAYER_SPEED;
		move_y = cos(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->l_r == 1)
	{
		move_x = sin(data->player->angle) * PLAYER_SPEED;
		move_y = -cos(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->u_d == -1)
	{
		move_x = cos(data->player->angle) * PLAYER_SPEED;
		move_y = sin(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->u_d == 1)
	{
		move_x = -cos(data->player->angle) * PLAYER_SPEED;
		move_y = -sin(data->player->angle) * PLAYER_SPEED;
	} */
	// move(data, data->map->map2d, move_x, move_y);
	if (data->player->u_d == 1)
		choose_mov(data, data->player, data->player->angle);
	if (data->player->u_d == -1)
		choose_mov(data, data->player, data->player->angle - M_PI);
	if (data->player->l_r == 1)
		choose_mov(data, data->player, data->player->angle - (M_PI / 2));
	if (data->player->l_r == -1)
		choose_mov(data, data->player, data->player->angle - (M_PI + (M_PI / 2)));
}
