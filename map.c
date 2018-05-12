/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:04:23 by atikhono          #+#    #+#             */
/*   Updated: 2018/05/11 20:43:34 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "main.h"

void	find_center(t_mlx *ptr)
{
	int		i;
	int		j;

	ptr->h_min = ptr->s_pix[0][0]->y;
	ptr->h_max = ptr->s_pix[0][0]->y;
	ptr->w_min = ptr->s_pix[0][0]->x;
	ptr->w_max = ptr->s_pix[0][0]->x;
	i = 0;
	while (ptr->s_pix[i] != NULL)
	{
		j = 0;
		while (ptr->s_pix[i][j] != NULL)
		{
			ptr->h_min = (ptr->s_pix[i][j]->y < ptr->h_min ? \
					ptr->s_pix[i][j]->y : ptr->h_min);
			ptr->h_max = (ptr->s_pix[i][j]->y > ptr->h_max ? \
					ptr->s_pix[i][j]->y : ptr->h_max);
			ptr->w_min = (ptr->s_pix[i][j]->x < ptr->w_min ? \
					ptr->s_pix[i][j]->x : ptr->w_min);
			ptr->w_max = (ptr->s_pix[i][j]->x > ptr->w_max ? \
					ptr->s_pix[i][j]->x : ptr->w_max);
			++j;
		}
		++i;
	}
}

/*void 	fill(t_mlx ptr, double x, double y, int i, int j, char dir)
{
	if (dir == 'r')
	{
		p.x0 = (int)(ptr.s_pix[i][j]->x * a + x);
		p.y0 = (int)(ptr.s_pix[i][j]->y * a + y);
		p.x1 = (int)(ptr.s_pix[i][j + 1]->x * a + x);
		p.y1 = (int)(ptr.s_pix[i][j + 1]->y * a + y);
	}
	if (dir == 'd')
	{




	}
}*/

void	draw_h(t_mlx ptr, t_point p, t_buff b)
{
	int 	i;
	int 	j;
	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j + 1] != NULL)
		{
			p.x0 = (int)(ptr.s_pix[i][j]->x * ptr.scale + b.x);
			p.y0 = (int)(ptr.s_pix[i][j]->y * ptr.scale + b.y);
			p.x1 = (int)(ptr.s_pix[i][j + 1]->x * ptr.scale + b.x);
			p.y1 = (int)(ptr.s_pix[i][j + 1]->y * ptr.scale + b.y);
			draw_line(&p, ptr);
			++j;
		}
		++i;
	}
}

void	draw_v(t_mlx ptr, t_point p, t_buff b)
{
	int 	i;
	int 	j;

	i = 0;
	while (ptr.s_pix[i] != NULL && ptr.s_pix[i + 1] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j] != NULL && ptr.s_pix[i + 1][j] != NULL)
		{
			p.x0 = (int)(ptr.s_pix[i][j]->x * ptr.scale + b.x);
			p.y0 = (int)(ptr.s_pix[i][j]->y * ptr.scale + b.y);
			p.x1 = (int)(ptr.s_pix[i + 1][j]->x * ptr.scale + b.x);
			p.y1 = (int)(ptr.s_pix[i + 1][j]->y * ptr.scale + b.y);
			draw_line(&p, ptr);
			++j;
		}
		++i;
	}
}

void	put_map(t_mlx ptr)
{
	t_buff		b;
	t_point 	p;

	find_center(&ptr);
	b.x = 600 + ptr.mx - (ptr.w_max + ptr.w_min) * ptr.scale / 2;
	b.y = 300 + ptr.my - (ptr.h_max + ptr.h_min) * ptr.scale / 2;
	mlx_clear_window(ptr.mlx, ptr.win);
	draw_h(ptr, p, b);
	draw_v(ptr, p, b);
}
