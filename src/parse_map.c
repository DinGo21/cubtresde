/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:57:01 by disantam          #+#    #+#             */
/*   Updated: 2024/07/15 12:46:53 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(t_mlx *data, t_map *map)
{
	int y;
	int	x;
	char *newline;

	y = 0;
	x = 0;
	while (map->map2d[y] != NULL)
	{
		x = ft_strlen(map->map2d[y]);
		if (x < map->w_map)
		{
			newline = ft_calloc(sizeof(char), map->w_map + 1);
			if (!newline)
				mlx_error(data, strerror(errno));
			ft_strlcpy(newline, map->map2d[y], x + 1);
			ft_memset(newline + x, ' ', map->w_map - x);
			free(map->map2d[y]);
			map->map2d[y] = newline;
		}
		y++;
	}
}

static void	get_mapsize(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while(map->map2d[y] != NULL)
	{
		x = 0;
		while (map->map2d[y][x] != '\0')
		{
			x++;
		}
		if (x > map->w_map)
		{
			map->w_map = x;
		}
		y++;
	}
	map->h_map = y;
	map->s_map = map->w_map + map->h_map;
}

void	parse_map(t_mlx *data, t_map *map, char *line, int fd)
{
	char *tmp;

	tmp = ft_strdup("");
	while (line)
	{
		tmp = ft_join(tmp, line);
		free(line);
		if (!tmp)
		{
			mlx_error(data, strerror(errno));
		}
		line = get_next_line(fd);
	}
	map->map2d = ft_split(tmp, '\n');
	free(tmp);
	if (!map->map2d)
	{
		mlx_error(data, strerror(errno));
	}
	get_mapsize(map);
	fill_map(data, map);
	print_matrix(map->map2d);
	check_map(data, map);
}


