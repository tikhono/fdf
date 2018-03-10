/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:25:11 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:36:37 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;

	i = 0;
	while (i < n)
	{
		if (((char*)s)[i] == (char)c)
		{
			return (((char*)s + i));
		}
		++i;
	}
	return (NULL);
}
