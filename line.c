/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:05 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/10 17:47:07 by atikhono         ###   ########.fr       */
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
	if (labs(*y1 - *y0) > labs(*x1 - *x0))
	{
		swap(x0, y0);
		swap(x1, y1);
	}
	if (*x0 > *x1)
	{
		swap(x0, x1);
		swap(y0, y1);
	}
}

void	put_pixel(int x, int y, double c, void *mlx, void *win)
{
	int		alpha;
	int		argb;

	alpha = (c * 1000) / FACTOR;
	alpha <<= 24;
	argb = 0x0000FF00;
	argb <<= 12;
	argb >>= 12;
	argb += alpha;
	mlx_pixel_put(mlx, win, x, y, argb);
}

void	draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	double	dist;
	double	sqr;
	int		x;
	int 	y;

	sqr = sqrt((y1 - y0)*(y1 - y0) + (x1 - x0)*(x1 - x0));
	y = y0;
	x = x0;
	while (y <= y1)
	{
		while (x <= x1)
		{
			//go throgh x until right dist
			dist = fabs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
			while (dist > 1)
			{
				++x;
				dist = fabs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
			}
			//go throgh x until wrong dist
			dist = fabs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
			while (dist <= 1)
			{
				put_pixel(x, y, dist, mlx, win);
				++x;
				dist = fabs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
			}
			//change start point (x)
			x = x0;
		}
		++y;
	}



}
