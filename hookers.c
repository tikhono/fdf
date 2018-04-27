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

#include <printf.h>
#include "main.h"

void	transform(t_mlx ptr)
{
	int		i;
	int		j;
	int 	temp;

	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j])
		{
			//x
			temp = ptr.s_pix[i][j]->y;
			ptr.s_pix[i][j]->y = (int) (temp * cos(ptr.ax) + ptr.s_pix[i][j]->z * sin(ptr.ax));
			ptr.s_pix[i][j]->z = (int) (ptr.s_pix[i][j]->z * cos(ptr.ax) - temp * sin(ptr.ax));
			//y
			temp = ptr.s_pix[i][j]->x;
			ptr.s_pix[i][j]->x = (int) (temp * cos(ptr.ay) + ptr.s_pix[i][j]->z * sin(ptr.ay));
			ptr.s_pix[i][j]->z = (int) (ptr.s_pix[i][j]->z * cos(ptr.ay) - temp * sin(ptr.ay));
			//z
			temp = ptr.s_pix[i][j]->x;
			ptr.s_pix[i][j]->x = (int) (temp * cos(ptr.az) - ptr.s_pix[i][j]->y * sin(ptr.az));
			ptr.s_pix[i][j]->y = (int) (ptr.s_pix[i][j]->y * cos(ptr.az) + temp * sin(ptr.az));
			++j;
		}
		++i;
	}
}

void	rot(int key, t_mlx ptr)
{
	int		i;
	int		j;
	double 	a;

	a = 10 * M_PI / 180;
	i = 0;
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
	transform(ptr);
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
