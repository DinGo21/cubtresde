/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:09:58 by disantam          #+#    #+#             */
/*   Updated: 2024/07/15 13:06:34 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_matrix(char **matrix)
{
	int	i;
	
	if (matrix != NULL)
	{
		i = 0;
		while (matrix[i] != NULL)
		{
			free(matrix[i++]);
		}
		free(matrix);
	}
}

void	free_mlx(t_mlx *data)
{
	int	i;

	i = 0;
	if (data->img != NULL)
	{
		mlx_delete_image(data->mlx, data->img);
	}
	mlx_close_window(data->mlx);
	while (i < 4)
	{
		if (data->textures[i] != NULL)
		{
			mlx_delete_texture(data->textures[i]);
		}
		i++;
	}
	if (data->mlx != NULL)
	{
		mlx_terminate(data->mlx);
	}
	free(data->map);
	free(data->player);
	free(data);
}

void	free_map(t_map *map)
{
	free_matrix(map->map2d);
	free_matrix(map->ff);
	free_matrix(map->cc);
	if (map->txtr[0] != NULL)
	{
		free(map->txtr[0]);
	}
	if (map->txtr[1] != NULL)
	{
		free(map->txtr[1]);
	}
	if (map->txtr[2] != NULL)
	{
		free(map->txtr[2]);
	}
	if (map->txtr[3] != NULL)
	{
		free(map->txtr[3]);
	}
}

void	ft_error(char *err_message)
{
	int	nb;

	nb = 0;
	if (err_message != NULL)
	{
		nb = write(2, "Error\n", 6);
		nb = write(2, err_message, ft_strlen(err_message));
		nb = write(2, "\n", 1);
	}
	(void)nb;
}

void	mlx_error(t_mlx *data, char *err_message)
{
	free_map(data->map);
	free_mlx(data);
	ft_error(err_message);
	exit(EXIT_FAILURE);
}
