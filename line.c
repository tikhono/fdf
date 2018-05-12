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

void	compare(int *x0, int *y0, int *x1, int *y1)
{
	int temp;

	if (*x0 > *x1)
	{
		temp = *x0;
		*x0 = *x1;
		*x1 = temp;
		temp = *y0;
		*y0 = *y1;
		*y1 = temp;
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

double	find_dist(t_point *p, double sqr, int x, int y)
{
	double res;

	res = abs((p->y1 - p->y0) * x - \
	(p->x1 - p->x0) * y + p->x1 * p->y0 - p->y1 * p->x0) / sqr;
	return (res);
}

void	draw_line(t_point *p, t_mlx ptr)
{
	double	dist;
	double	sqr;
	int		x;
	int		y;
	int		start;

	compare(&p->x0, &p->y0, &p->x1, &p->y1);
	y = p->y0;
	x = p->x0;
	start = p->x0;
	sqr = sqrt(pow((p->y1 - p->y0), 2.0) + pow((p->x1 - p->x0), 2.0));
	while (1)
	{
		dist = find_dist(p, sqr, x, y);
		while (dist > 1 && x <= p->x1)
		{
			start = x++;
			dist = find_dist(p, sqr, x, y);
		}
		while (dist <= 1 && x <= p->x1)
		{
			put_pixel(x++, y, dist, ptr);
			dist = find_dist(p, sqr, x, y);
		}
		if (y == p->y1)
			break ;
		x = start;
		p->y0 < p->y1 ? ++y : --y;
	}
}
