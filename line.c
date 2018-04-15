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

	alpha = (int)((c * 1001) / FACTOR);
	alpha <<= 24;
	argb = 0x00F90000;
	argb += alpha;
	mlx_pixel_put(mlx, win, x, y, argb);
}

void	draw_line(int x0, int y0, int x1, int y1, void *mlx, void *win)
{
	double	dist;
	double	sqr;
	int		x;
	int 	start;
	int 	y;

	compare(&x0, &y0, &x1, &y1);
	y = y0;
	x = x0;
	start = x0;
	sqr = sqrt((y1 - y0)*(y1 - y0) + (x1 - x0)*(x1 - x0));
	while (1)
	{
		dist = abs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
		while (dist > 1 && x <= x1)
		{
			start = x++;
			dist = abs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
		}
		while (dist <= 1 && x <= x1)
		{
			put_pixel(x++, y, dist, mlx, win);
			dist = abs((y1 - y0)*x - (x1 - x0)*y + x1*y0 - y1*x0) / sqr;
		}
		if (y == y1)
			break ;
		x = start;
		y0 < y1 ? ++y : --y;
	}
}
