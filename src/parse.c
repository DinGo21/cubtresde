/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:07:53 by disantam          #+#    #+#             */
/*   Updated: 2024/07/29 13:59:13 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_rgb(t_mlx *data, char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		while (rgb[i][j] != '\0' && rgb[i][j] != '\n')
		{
			if (!ft_isdigit(rgb[i][j]))
				mlx_error(data, "rgb must contain numbers");
			j++;
		}
		i++;
	}
	if (i != 3)
		mlx_error(data, "wrong rgb format");
	rgb[2][3] = '\0';
}

static int	get_rgb(t_map *map, char *line)
{
	int	i;

	i = 1;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (ft_error("missing element"), -1);
	if (!ft_strncmp(line, "F", 1))
	{
		if (map->ff != NULL)
			return (ft_error("element already set"), -1);
		map->ff = ft_split(line + i, ',');
		if (!map->ff)
			return (ft_error(strerror(errno)), -1);
	}
	if (!ft_strncmp(line, "C", 1))
	{
		if (map->cc != NULL)
			return (ft_error("element already set"), -1);
		map->cc = ft_split(line + i, ',');
		if (!map->cc)
			return (ft_error(strerror(errno)), -1);
	}
	map->count++;
	return (0);
}

static int	get_texture(t_map *map, char *line)
{
	int	i;
	int	in;

	if (!ft_strncmp(line, "NO", 2))
		in = NO;
	if (!ft_strncmp(line, "SO", 2))
		in = SO;
	if (!ft_strncmp(line, "WE", 2))
		in = WE;
	if (!ft_strncmp(line, "EA", 2))
		in = EA;
	i = 2;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (ft_error("missing element"), -1);
	if (map->txtr[in] != NULL)
		return (ft_error("element already set"), -1);
	map->txtr[in] = ft_strdup(line + i);
	if (ft_strncmp(ft_strrchr(map->txtr[in], '.'), ".png", 4) != 0)
		return (ft_error("wrong filetype"), -1);
	*(ft_strrchr(map->txtr[in], '\n')) = '\0';
	map->count++;
	return (0);
}

static int	check_element(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\t' || line[i] == ' ')
		i++;
	if (line[i] == '\n')
	{
		return (free(line), 0);
	}
	else if (line[i] == '\0')
	{
		return (ft_error("unexpected EOF"), free(line), -1);
	}
	if (is_element(line + i) == 1)
	{
		if (get_texture(map, line + i) < 0)
			return (free(line), -1);
	}
	else if (is_element(line + i) == 2)
	{
		if (get_rgb(map, line + i) < 0)
			return (free(line), -1);
	}
	return (free(line), 0);
}

void	parse_elements(t_mlx *data, t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		mlx_error(data, "file is empty");
		exit(EXIT_FAILURE);
	}
	while (line && map->count < 6)
	{
		if (check_element(map, line) < 0)
			mlx_error(data, NULL);
		line = get_next_line(fd);
	}
	if (map->count < 6)
		mlx_error(data, "missing necessary elements");
	if (!line)
		mlx_error(data, "unexpected EOF");
	check_rgb(data, map->cc);
	check_rgb(data, map->ff);
	parse_map(data, map, line, fd);
}
