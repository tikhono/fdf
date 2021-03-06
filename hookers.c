/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:29:06 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/27 19:47:15 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	transform(t_mlx *ptr)
{
	int		i;
	int		j;
	double	temp;

	i = -1;
	while (ptr->s_pix[++i] != NULL)
	{
		j = -1;
		while (ptr->s_pix[i][++j])
		{
			ptr->s_pix[i][j]->y = \
			(double)(i) * cos(ptr->ax) + ptr->s_pix[i][j]->oz * sin(ptr->ax);
			ptr->s_pix[i][j]->z = \
			ptr->s_pix[i][j]->oz * cos(ptr->ax) - (double)(i) * sin(ptr->ax);
			ptr->s_pix[i][j]->x = \
			(double)(j) * cos(ptr->ay) + ptr->s_pix[i][j]->z * sin(ptr->ay);
			ptr->s_pix[i][j]->z = \
			ptr->s_pix[i][j]->z * cos(ptr->ay) - (double)(j) * sin(ptr->ay);
			temp = ptr->s_pix[i][j]->x;
			ptr->s_pix[i][j]->x = \
			temp * cos(ptr->az) - ptr->s_pix[i][j]->y * sin(ptr->az);
			ptr->s_pix[i][j]->y = \
			ptr->s_pix[i][j]->y * cos(ptr->az) + temp * sin(ptr->az);
		}
	}
}

void	rot(int key, t_mlx *ptr)
{
	double	a;

	a = 5 * M_PI / 180;
	if (key == 0)
		ptr->ax += a;
	if (key == 1)
		ptr->ay += a;
	if (key == 2)
		ptr->az += a;
	if (key == 12)
		ptr->ax -= a;
	if (key == 13)
		ptr->ay -= a;
	if (key == 14)
		ptr->az -= a;
	transform(ptr);
	put_map(*ptr);
}

void	move(int key, t_mlx *ptr)
{
	if (key == 123)
		ptr->mx -= 5;
	if (key == 124)
		ptr->mx += 5;
	if (key == 125)
		ptr->my += 5;
	if (key == 126)
		ptr->my -= 5;
	put_map(*ptr);
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
	if ((0 <= key && key <= 2) || (12 <= key && key <= 14))
		rot(key, ptr);
	if (123 <= key && key <= 126)
		move(key, ptr);
	if (key == 3 || key == 15)
		zoom(key, ptr);
	if (key == 53)
		exit(0);
	return (0);
}
