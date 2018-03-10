/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:31:24 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/20 17:54:46 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	i;

	i = 0;
	if (dst > src)
	{
		i = len;
		while (i > 0)
		{
			--i;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	if (dst < src)
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			++i;
		}
	}
	return (dst);
}
