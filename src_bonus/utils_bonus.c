/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpaez-ga <gpaez-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:39:56 by disantam          #+#    #+#             */
/*   Updated: 2024/08/01 01:50:42 by gpaez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	get_txtr_dir(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (NO);
	if (!ft_strncmp(line, "SO", 2))
		return (SO);
	if (!ft_strncmp(line, "WE", 2))
		return (WE);
	if (!ft_strncmp(line, "EA", 2))
		return (EA);
	return (0);
}

void	print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		printf("%s\n", matrix[i++]);
	}
}

int	is_element(char *line)
{
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
		|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
	{
		return (1);
	}
	if (!ft_strncmp(line, "F", 1) || !ft_strncmp(line, "C", 1))
	{
		return (2);
	}
	return (0);
}

int	isplayer(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		return (1);
	}
	return (0);
}

char	*ft_join(char *s1, char *s2)
{
	size_t	i;
	size_t	c1;
	size_t	c2;
	char	*str;

	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	str = malloc(c1 + c2 + 1);
	if (!str)
	{
		return (NULL);
	}
	i = -1;
	while (++i < c1)
	{
		str[i] = s1[i];
	}
	i = -1;
	while (c1 + ++i < c1 + c2)
	{
		str[c1 + i] = s2[i];
	}
	str[c1 + c2] = '\0';
	return (free(s1), str);
}
