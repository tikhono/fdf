/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:04:23 by atikhono          #+#    #+#             */
/*   Updated: 2018/05/07 19:27:07 by atikhono         ###   ########.fr       */
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

void	put_map(t_mlx ptr, int a)
{
	int		i;
	int		j;
	double	x;
	double	y;

	find_center(&ptr);
	i = 0;
	j = 0;
	x = 600 + ptr.mx - (ptr.w_max + ptr.w_min) * ptr.scale / 2;
	y = 300 + ptr.my - (ptr.h_max + ptr.h_min) * ptr.scale / 2;
	mlx_clear_window(ptr.mlx, ptr.win);
	while (ptr.s_pix[i] != NULL && ptr.s_pix[i + 1])
	{
		while (ptr.s_pix[i][j] != NULL && ptr.s_pix[i][j + 1] != NULL && ptr.s_pix[i + 1][j] != NULL)
		{
			draw_line((int)(ptr.s_pix[i][j]->x * a + x),
					  (int)(ptr.s_pix[i][j]->y * a + y),
					  (int)(ptr.s_pix[i][j + 1]->x * a + x),
					  (int)(ptr.s_pix[i][j + 1]->y * a + y), ptr.mlx, ptr.win);
			draw_line((int)(ptr.s_pix[i][j]->x * a + x),
					  (int)(ptr.s_pix[i][j]->y * a + y),
					  (int)(ptr.s_pix[i + 1][j]->x * a + x),
					  (int)(ptr.s_pix[i + 1][j]->y * a + y), ptr.mlx, ptr.win);
			++j;
		}
		draw_line((int)(ptr.s_pix[i][j]->x * a + x),
				  (int)(ptr.s_pix[i][j]->y * a + y),
				  (int)(ptr.s_pix[i + 1][j]->x * a + x),
				  (int)(ptr.s_pix[i + 1][j]->y * a + y), ptr.mlx, ptr.win);
		j = 0;
		++i;
	}
	while (ptr.s_pix[i][j] != NULL && ptr.s_pix[i][j + 1])
	{
		draw_line((int)(ptr.s_pix[i][j]->x * a + x),
				  (int)(ptr.s_pix[i][j]->y * a + y),
				  (int)(ptr.s_pix[i][j + 1]->x * a + x),
				  (int)(ptr.s_pix[i][j + 1]->y * a + y), ptr.mlx, ptr.win);
		++j;
	}
}
