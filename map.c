/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 17:04:23 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/15 17:04:26 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_map(t_mlx ptr)
{
	int		i;
	int		j;
	int		a;

	a = 50;
	i = 0;
	j = 0;
	while (ptr.s_pix[i] != NULL && ptr.s_pix[i + 1])
	{
		while (ptr.s_pix[i][j] != NULL && ptr.s_pix[i][j + 1] != NULL && ptr.s_pix[i + 1][j] != NULL)
		{
			draw_line(ptr.s_pix[i][j]->x * a, ptr.s_pix[i][j]->y * a, ptr.s_pix[i][j + 1]->x * a, ptr.s_pix[i][j + 1]->y * a, ptr.mlx, ptr.win);
			draw_line(ptr.s_pix[i][j]->x * a, ptr.s_pix[i][j]->y * a, ptr.s_pix[i + 1][j]->x * a, ptr.s_pix[i + 1][j]->y * a, ptr.mlx, ptr.win);
			++j;
		}
		draw_line(ptr.s_pix[i][j]->x * a, ptr.s_pix[i][j]->y * a, ptr.s_pix[i + 1][j]->x * a, ptr.s_pix[i + 1][j]->y * a, ptr.mlx, ptr.win);
		j = 0;
		++i;
	}
	while (ptr.s_pix[i][j] != NULL && ptr.s_pix[i][j + 1])
	{
		draw_line(ptr.s_pix[i][j]->x * a, ptr.s_pix[i][j]->y * a, ptr.s_pix[i][j + 1]->x * a, ptr.s_pix[i][j + 1]->y * a, ptr.mlx, ptr.win);
		++j;
	}
}
