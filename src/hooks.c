/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:46:49 by disantam          #+#    #+#             */
/*   Updated: 2024/07/29 14:07:56 by disantam         ###   ########.fr       */
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

void	move(t_mlx *data, char **map, float move_x, float move_y)
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
}

void	hooks(t_mlx *data, float move_x, float move_y)
{
	if (data->player->rot == 1)
		rotate(data, data->player->rot);
	if (data->player->rot == -1)
		rotate(data, data->player->rot);
	if (data->player->l_r == 1)
	{
		move_x = -sin(data->player->angle) * PLAYER_SPEED;
		move_y = cos(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->l_r == -1)
	{
		move_x = sin(data->player->angle) * PLAYER_SPEED;
		move_y = -cos(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->u_d == 1)
	{
		move_x = cos(data->player->angle) * PLAYER_SPEED;
		move_y = sin(data->player->angle) * PLAYER_SPEED;
	}
	if (data->player->u_d == -1)
	{
		move_x = -cos(data->player->angle) * PLAYER_SPEED;
		move_y = -sin(data->player->angle) * PLAYER_SPEED;
	}
	move(data, data->map->map2d, move_x, move_y);
}
