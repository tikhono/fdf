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
	int 	a;

	a = 5;
	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j])
		{
			if (key == 0)
				ptr.ax += a;
			if (key == 1)
				ptr.ay += a;
			if (key == 2)
				ptr.az += a;
			if (key == 12)
				ptr.ax -= a;
			if (key == 13)
				ptr.ay -= a;
			if (key == 14)
				ptr.az -= a;
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
	int		mx;
	int		my;

	mx = key == 123 ? -1 : 0;
	mx = key == 124 ? 1 : mx;
	my = key == 126 ? -1 : 0;
	my = key == 125 ? 1 : my;
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
	put_map(ptr);
}

void	zoom(int key, t_mlx *ptr)
{
	if (key == 3)
		ptr->scale += 1;
	if (key == 15 && ptr->scale != 1)
		ptr->scale -= 1;
	put_map(*ptr);
}

int		call_hookers(int key, t_mlx *ptr)
{
	ptr->ax = 0;
	ptr->ay = 0;
	ptr->az = 0;
	if ((0 <= key && key <= 2) || (12 <= key && key <= 14))
		rot(key, *ptr);
	if (123 <= key && key <= 126)
		move(key, *ptr);
	if (key == 3 || key == 15)
		zoom(key, ptr);
	return (0);
}
