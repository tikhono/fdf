/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:29:06 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/10 17:47:23 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rot(int key, t_mlx ptr)
{
	int		i;
	int		j;
	int 	ax;
	int 	ay;
	int 	az;

	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j])
		{
			//ptr.s_pix[i][j]->x = cos();
			++j;
		}
		++i;
	}
	put_map(ptr);
}

void	move(int key, t_mlx ptr)
{
	int		i;
	int		j;
	int 	mx;
	int 	my;

	if (key == 123)
		mx = -1;
	else if (key == 124)
		mx = 1;
	else
		mx = 0;
	if (key == 125)
		my = -1;
	else if (key == 126)
		my = 1;
	else
		my = 0;
	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j] != NULL)
		{
			ptr.s_pix[i][j]->x += mx;
			ptr.s_pix[i][j]->y += my;
			++j;
		}
		++i;
	}
	mlx_clear_window(ptr.mlx, ptr.win);
	put_map(ptr);
}

void	zoom(int key, t_mlx ptr)
{}

int		call_hookers(int key, t_mlx *ptr)
{
	if ((0 <= key && key <= 2) || (12 <= key && key <= 14))
		rot(key, *ptr);
	if (123 <= key && key <= 126)
		move(key, *ptr);
	if (key == 3 || key == 15)
		zoom(key, *ptr);
	return (0);
}
