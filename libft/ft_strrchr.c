/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:22:53 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:40:17 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cur;
	char	*p;

	cur = NULL;
	p = (char *)s;
	while (*p != '\0')
	{
		if (*p == c)
			cur = p;
		++p;
	}
	if (c == '\0')
		return (p);
	return (cur);
}
