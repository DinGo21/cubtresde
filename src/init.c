/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:25:19 by disantam          #+#    #+#             */
/*   Updated: 2024/07/24 17:12:41 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	load_textures(t_mlx *data, t_map *map)
{
	printf("%s\n", map->txtr[0]);
	printf("%s\n", map->txtr[1]);
	printf("%s\n", map->txtr[2]);
	printf("%s\n", map->txtr[3]);
	data->textures[NO] = mlx_load_png(map->txtr[NO]);
	if (!data->textures[NO])
		return (-1);
	data->textures[SO] = mlx_load_png(map->txtr[SO]);
	if (!data->textures[SO])
		return (-1);
	data->textures[WE] = mlx_load_png(map->txtr[WE]);
	if (!data->textures[WE])
		return (-1);
	data->textures[EA] = mlx_load_png(map->txtr[EA]);
	if (!data->textures[EA])
		return (-1);
	return (0);
}

void	init_player(t_player *player, t_map *map)
{
	char	dir;

	dir = map->map2d[map->plyr_y][map->plyr_x];
	player->x = (map->plyr_x * TILE_SIZE) + TILE_SIZE / 2;
	player->y = (map->plyr_y * TILE_SIZE) + TILE_SIZE / 2;
	player->l_r = 0;
	player->u_d = 0;
	player->fov = (FOV * M_PI / 180);
	if (dir == 'N')
		player->angle = M_PI / 2;
	if (dir == 'S')
		player->angle = M_PI + (M_PI / 2);
	if (dir == 'E')
		player->angle = 0;
	if (dir == 'W')
		player->angle = M_PI;
}


void	init_data(t_mlx *data)
{
	data->map = malloc(sizeof(t_map));
	data->player = malloc(sizeof(t_player));
	if (!data->map || !data->player)
		mlx_error(data, strerror(errno));
	data->mlx = NULL;
	data->img = NULL;
	data->map->w_map = 0;
	data->map->h_map = 0;
	data->map->plyr_x = 0;
	data->map->plyr_y = 0;
	data->map->count = 0;
	data->textures[NO] = NULL;
	data->textures[SO] = NULL;
	data->textures[WE] = NULL;
	data->textures[EA] = NULL;
	data->map->map2d = NULL;
	data->map->cc = NULL;
	data->map->ff = NULL;
	data->map->txtr[NO] = NULL;
	data->map->txtr[SO] = NULL;
	data->map->txtr[WE] = NULL;
	data->map->txtr[EA] = NULL;
}
