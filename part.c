/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:06 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/04 19:55:24 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double	ipart(double x)
{
	return (floor(x));
}

double	round(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	return (floor(x));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}
