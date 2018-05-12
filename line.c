/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:05 by atikhono          #+#    #+#             */
/*   Updated: 2018/05/11 20:08:39 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "main.h"

void	swap(int *a, int *b)
{
	int	x;

	x = *a;
	*a = *b;
	*b = x;
}

void	compare(int *x0, int *y0, int *x1, int *y1)
{
	if (*x0 > *x1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}
}

void	put_pixel(int x, int y, double c, t_mlx ptr)
{
	int		alpha;
	int		argb;

	alpha = (int)((c * 1001) / FACTOR);
	alpha <<= 24;
	argb = 0x00FFFFFF;
	argb += alpha;
	mlx_pixel_put(ptr.mlx, ptr.win, x, y, argb);
}

void	draw_line(t_point *p0, t_mlx ptr)
{
	double	dist;
	double	sqr;
	int		x;
	int		start;
	int		y;

	compare(&p0->x0, &p0->y0, &p0->x1, &p0->y1);
	y = p0->y0;
	x = p0->x0;
	start = p0->x0;
	sqr = sqrt((p0->y1 - p0->y0) * (p0->y1 - p0->y0) + (p0->x1 - p0->x0) * (p0->x1 - p0->x0));
	while (1)
	{
		dist = abs((p0->y1 - p0->y0) * x - (p0->x1 - p0->x0) * y + p0->x1 * p0->y0 - p0->y1 * p0->x0) / sqr;
		while (dist > 1 && x <= p0->x1)
		{
			start = x++;
			dist = abs((p0->y1 - p0->y0) * x - (p0->x1 - p0->x0) * y + p0->x1 * p0->y0 - p0->y1 * p0->x0) / sqr;
		}
		while (dist <= 1 && x <= p0->x1)
		{
			put_pixel(x++, y, dist, ptr);
			dist = abs((p0->y1 - p0->y0) * x - (p0->x1 - p0->x0) * y + p0->x1 * p0->y0 - p0->y1 * p0->x0) / sqr;
		}
		if (y == p0->y1)
			break ;
		x = start;
		p0->y0 < p0->y1 ? ++y : --y;
	}
}
