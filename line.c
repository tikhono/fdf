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
	int		i;
	int		dx;
	int		dy;
	double	grad;
	double	intery;

	compare(&x0, &y0, &x1, &y1);
	dx = x1 - x0;
	dy = y1 - y0;
	grad = dy / dx;
	if (dx == 0.0)
		grad = 1.0;
	intery = y0;
	if (labs(y1 - y0) > labs(x1 - x0))
	{
		i = x0;
		while (i < x1)
		{
		//	put_pixel(ipart(intery) + 2, i, rfpart(intery), mlx, win);
		//	put_pixel(ipart(intery) + 1, i, rfpart(intery), mlx, win);
			put_pixel(ipart(intery), i, fpart(intery), mlx, win);
			put_pixel(ipart(intery) - 1, i, rfpart(intery), mlx, win);
		//	put_pixel(ipart(intery) - 2, i, rfpart(intery), mlx, win);
			intery = intery + grad;
			++i;
		}
	}
	else
	{
		i = x0;
		while (i < x1)
		{
		//	put_pixel(i, ipart(intery) + 2, rfpart(intery), mlx, win);
		//	put_pixel(i, ipart(intery) + 1, rfpart(intery), mlx, win);
			put_pixel(i, ipart(intery), fpart(intery), mlx, win);
			put_pixel(i, ipart(intery) - 1, rfpart(intery), mlx, win);
		//	put_pixel(i, ipart(intery) - 2, rfpart(intery), mlx, win);
			intery = intery + grad;
			++i;
		}
	}
}
