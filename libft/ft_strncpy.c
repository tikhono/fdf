/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 22:04:23 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:37:52 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned long int	i;

	i = 0;
	if (!src[i])
		while (i < len)
			dst[i++] = '\0';
	while (i < len)
	{
		dst[i] = src[i];
		++i;
		if (!src[i])
			while (i < len)
				dst[i++] = '\0';
	}
	return (dst);
}
