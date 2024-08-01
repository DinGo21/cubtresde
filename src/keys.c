/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:41:48 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 11:42:22 by disantam         ###   ########.fr       */
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
