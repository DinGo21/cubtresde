/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:49 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 15:36:24 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	coll(t_mlx *data, float ang, int ctr)
{
	int	dist;

	dist = 10;
	if ((data->map->map2d[(int)(data->player->y / TILE_SIZE)]
		[((int)data->player->x + dist) / TILE_SIZE] == '1')
		&& (ang <= M_PI / 2 || ang >= M_PI + (M_PI / 2)) && ctr == 1)
		return (1);
	if (data->map->map2d[(int)(data->player->y / TILE_SIZE)]
		[((int)data->player->x - dist) / TILE_SIZE] == '1'
		&& (ang >= M_PI / 2 && ang <= M_PI + (M_PI / 2)) && ctr == 1)
		return (1);
	if ((data->map->map2d[((int)data->player->y - dist) / TILE_SIZE]
			[(int)(data->player->x / TILE_SIZE)] == '1')
		&& ang >= 0 && ang <= M_PI && ctr == 2)
		return (2);
	if (data->map->map2d[((int)data->player->y + dist)
			/ TILE_SIZE][(int)(data->player->x / TILE_SIZE)] == '1'
		&& ang <= 2 * M_PI && ang >= M_PI && ctr == 2)
		return (2);
	return (0);
}

void	move(t_point end, t_player *player, t_mlx *data, float ang)
{
	float	delta_x;
	float	delta_y;
	int		pixels;
	int		spd;

	if (player->u_d == 1 && (player->l_r == 1 || player->l_r == -1))
		spd = PLAYER_SPEED / 2;
	else if (player->u_d == -1 && (player->l_r == 1
			|| player->l_r == -1))
		spd = PLAYER_SPEED / 2;
	else
		spd = PLAYER_SPEED;
	delta_x = end.x - player->x;
	delta_y = end.y - player->y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x = delta_x / pixels;
	delta_y = delta_y / pixels;
	delta_x = delta_x * spd;
	delta_y = delta_y * spd;
	if (coll(data, ang, 1) != 1)
		player->x += delta_x * spd;
	if (coll(data, ang, 2) != 2)
		player->y += delta_y * spd;
}

void	choose_mov(t_mlx *data, t_player *player, float ang)
{
	t_ray	ray;
	float	v_inter;
	float	h_inter;

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
		move(ray.v, data->player, data, ang);
	else
		move(ray.h, data->player, data, ang);
}

void	hooks(t_mlx *data)
{
	if (data->player->rot == 1)
		rotate(data, data->player->rot);
	if (data->player->rot == -1)
		rotate(data, data->player->rot);
	if (data->player->u_d == 1)
	{
		choose_mov(data, data->player, data->player->angle);
	}
	if (data->player->u_d == -1)
	{
		choose_mov(data, data->player, data->player->angle
			- M_PI);
	}
	if (data->player->l_r == 1)
	{
		choose_mov(data, data->player, data->player->angle
			- (M_PI / 2));
	}
	if (data->player->l_r == -1)
	{
		choose_mov(data, data->player, data->player->angle
			- (M_PI + (M_PI / 2)));
	}
}

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
