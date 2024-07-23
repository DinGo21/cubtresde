/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:04:09 by disantam          #+#    #+#             */
/*   Updated: 2024/07/22 17:28:48 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	get_args(t_mlx *data, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(strerror(errno));
		exit(EXIT_FAILURE);
	}
	parse_elements(data, data->map, fd);
	close(fd);
}

void	game_loop(void *param)
{
	t_mlx	*data;
	// t_ray	ray;

	data = param;
	// raycast(data, &ray, data->player);
	drawang(data);
}

void	start_game(t_mlx *data)
{
	// t_ray ray;
	data->mlx = mlx_init(S_WIDTH, S_HEIGHT, "cuBit3D", true);
	if (!data->mlx)
	{
		mlx_error(data, strerror(errno));
	}
	init_player(data->player, data->map);
	if (load_textures(data, data->map) == -1)
	{
		mlx_error(data, "Problems while loading textures");
	}
	data->img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx, &game_loop, data);
	// raycast(data, &ray, data->player);
	mlx_loop(data->mlx);
}

int	main(int argc, char *argv[])
{
	t_mlx	*data;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub", 4) != 0)
	{
		ft_error("Filetype is not .cub");
		exit(EXIT_FAILURE);
	}
	data = malloc(sizeof(t_mlx));
	if (!data)
	{
		ft_error(strerror(errno));
		exit(EXIT_FAILURE);
	}
	init_data(data);
	get_args(data, argv[1]);
	start_game(data);
	free_map(data->map);
	free_mlx(data);
	return (EXIT_SUCCESS);
}
