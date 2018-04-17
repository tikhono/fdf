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

	i = 0;
	while (ptr.s_pix[i] != NULL)
	{
		j = 0;
		while (ptr.s_pix[i][j])
		{
			//count new z y z
			++j;
		}
		++i;
	}
	put_map(ptr);
}

void	move(int key, t_mlx ptr)
{}

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
