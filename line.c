/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:05 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/05 18:29:41 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <mlx.h>
#include "line.h"
#include "part.h"

void	swap(double *a, double *b)
{
	double	x;

	x = *a;
	*a = *b;
	*b = x;
}

void	compare(double *x0, double *y0, double *x1, double *y1)
{
	if (fabs(*y1 - *y0) > fabs(*x1 - *x0))
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

void	put_pixel(double x, double y, double c, void *mlx, void *win)
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

void	draw_line(double x0, double y0, double x1, double y1, void *mlx, void *win)
{
	double	i;
	double	dx;
	double	dy;
	double	grad;
	double	intery;

	compare(&x0, &y0, &x1, &y1);
	dx = x1 - x0;
	dy = y1 - y0;
	grad = dy / dx;
	if (dx == 0.0)
		grad = 1.0;
	intery = y0;
	if (fabs(y1 - y0) > fabs(x1 - x0))
	{
		i = x0;
		while (i <= x1)
		{
			put_pixel(ipart(intery) + 1.0, i, rfpart(intery), mlx, win);
			put_pixel(ipart(intery) - 1.0, i, rfpart(intery), mlx, win);
			put_pixel(ipart(intery), i, fpart(intery), mlx, win);
			intery = intery + grad;
			i += 1.0;
		}
	}
	else
	{
		i = x0;
		while (i <= x1)
		{
			put_pixel(i, ipart(intery) + 1.0, rfpart(intery), mlx, win);
			put_pixel(i, ipart(intery) - 1.0, rfpart(intery), mlx, win);
			put_pixel(i, ipart(intery), fpart(intery), mlx, win);
			intery = intery + grad;
			i += 1.0;
		}
	}
}
