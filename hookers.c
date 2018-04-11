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

void	rot(int key, t_pix ***arr)
{}

void	move(int key, t_pix ***arr)
{}

void	zoom(int key, t_pix ***arr)
{}

void	call_hookers(int key, t_pix ***arr)
{
	if ((0 <= key && key <= 2) || (12 <= key && key <= 14))
		rot(key, arr);
	if (123 <= key && key <= 126)
		move(key, arr);
	if (key == 3 || key == 15)
		zoom(key, arr);
}
