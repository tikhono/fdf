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

void 	put_map(t_mlx ptr)
{
	//using line draw map

	draw_line(100, 100, 100, 0, ptr.mlx, ptr.win);
	draw_line(100, 100, 200, 0, ptr.mlx, ptr.win);
	draw_line(100, 100, 200, 100, ptr.mlx, ptr.win);
	draw_line(100, 100, 200, 200, ptr.mlx, ptr.win);
	draw_line(100, 100, 100, 200, ptr.mlx, ptr.win);
	draw_line(100, 100, 0, 200, ptr.mlx, ptr.win);
	draw_line(100, 100, 0, 100, ptr.mlx, ptr.win);
	draw_line(100, 100, 0, 0, ptr.mlx, ptr.win);

	draw_line(100, 100, 150, 0, ptr.mlx, ptr.win);
	draw_line(100, 100, 200, 50, ptr.mlx, ptr.win);
	draw_line(100, 100, 200, 150, ptr.mlx, ptr.win);
	draw_line(100, 100, 150, 200, ptr.mlx, ptr.win);
	draw_line(100, 100, 50, 200, ptr.mlx, ptr.win);
	draw_line(100, 100, 0, 150, ptr.mlx, ptr.win);
	draw_line(100, 100, 0, 50, ptr.mlx, ptr.win);
	draw_line(100, 100, 50, 0, ptr.mlx, ptr.win);

}
