/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:09:45 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:38:14 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long int	i;

	i = 0;
	while (i < n && (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i]))
		++i;
	if (i != n)
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	else
		return (0);
}
