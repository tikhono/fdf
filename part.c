/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:34:06 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/05 21:33:37 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int		ipart(double x)
{
	return (floor(x));
}

int		rpart(double x)
{
	return (ipart(x + 0.5));
}

double	fpart(double x)
{
	if (x > 0)
		return (x - ipart(x));
	return (x - (ipart(x) + 1));
}

double	rfpart(double x)
{
	return (1 - fpart(x));
}
