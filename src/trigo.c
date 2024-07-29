/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 18:17:27 by disantam          #+#    #+#             */
/*   Updated: 2024/07/29 14:03:35 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	rads(float x)
{
	float	res;

	res = x * (M_PI / 180);
	return (res);
}

float	catopo(float ady, float ang)
{
	float	res;

	res = ady * tan(ang);
	return (res);
}

float	catady(float opo, float ang)
{
	float	res;

	res = opo / tan(ang);
	return (res);
}

float	hipo(float y, float x)
{
	float	h;

	h = sqrt((y * y) + (x * x));
	return (h);
}
