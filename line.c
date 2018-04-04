/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:05 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/04 21:11:05 by atikhono         ###   ########.fr       */
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
	double	xend;
	double	yend;
	double	xgap;
	double	xpxl1;
	double	ypxl1;
	double	xpxl2;
	double	ypxl2;

	compare(&x0, &y0, &x1, &y1);
	dx = x1 - x0;
	dy = y1 - y0;
	grad = dy / dx;
	if (dx == 0.0)
		grad = 1.0;
	xend = round(x0);
	yend = y0 + grad * (xend - x0);
	xgap = rfpart(x0 + 0.5);
	xpxl1 = xend;
	ypxl1 = ipart(yend);
	if (fabs(y1 - y0) > fabs(x1 - x0))
	{
		put_pixel(ypxl1, xpxl1, rfpart(yend) * xgap, mlx, win);
		put_pixel(ypxl1 + 1.0, xpxl1, fpart(yend) * xgap, mlx, win);
	}
	else
	{
		put_pixel(xpxl1, ypxl1, rfpart(yend) * xgap, mlx, win);
		put_pixel(xpxl1, ypxl1 + 1.0, fpart(yend) * xgap, mlx, win);
	}
	intery = yend + grad;	
	xend = round(x1);
	yend = y1 + grad * (xend - x1);
	xgap = fpart(x1 + 0.5);
	xpxl2 = xend;
	ypxl2 = ipart(yend);
	if (fabs(y1 - y0) > fabs(x1 - x0))
	{
		put_pixel(ypxl2, xpxl2, rfpart(yend) * xgap, mlx, win);
		put_pixel(ypxl2 + 1.0, xpxl2, fpart(yend) * xgap, mlx, win);
	}
	else
	{
		put_pixel(xpxl2, ypxl2, rfpart(yend) * xgap, mlx, win);
		put_pixel(xpxl2, ypxl2 + 1.0, fpart(yend) * xgap, mlx, win);
	}
	if (fabs(y1 - y0) > fabs(x1 - x0))
	{
		i = xpxl1 + 1.0;
		while (i <= xpxl2 - 1.0)
		{
			put_pixel(ipart(intery), i, rfpart(intery), mlx, win);
			put_pixel(ipart(intery) + 1.0, i, fpart(intery), mlx, win);
			intery = intery + grad;
			i += 1.0;
		}
	}
	else
	{
		i = xpxl1 + 1.0;
		while (i <= xpxl2 - 1.0)
		{
			put_pixel(i, ipart(intery), rfpart(intery), mlx, win);
			put_pixel(i, ipart(intery) + 1.0, fpart(intery), mlx, win);
			intery = intery + grad;
			i += 1.0;
		}
	}
}
