/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 19:21:41 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/16 16:51:55 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	binary_sqrt_search(long long int a, long long int lo, \
		long long int hi, int n)
{
	long long int cent;
	long long int pow;

	cent = (lo + hi) / 2;
	pow = ft_power(cent, n);
	if (cent + 1 > hi || cent - 1 < lo || a <= 0)
		return (0);
	if (pow > a)
		return (binary_sqrt_search(a, lo, cent, n));
	if (pow < a)
		return (binary_sqrt_search(a, cent, hi, n));
	if (pow == a)
		return (cent);
	return (a);
}

int			ft_root(int nb, int n)
{
	long long int a;

	a = (long long int)nb;
	if (a == 1)
		return (1);
	return (binary_sqrt_search(a, 0, (a / n), n));
}
