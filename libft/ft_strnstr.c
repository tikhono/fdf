/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:50:22 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:40:36 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*s;
	char	*n;
	size_t	a;
	size_t	b;

	h = (char *)haystack;
	s = (char *)haystack;
	n = (char *)needle;
	if (!*n)
		return (h);
	a = -1;
	while (*h && ++a < len)
	{
		b = -1;
		while (*h == *n && *h && *(n++) && a + ++b < len)
			++h;
		if (!*n)
			return (s);
		h = ++s;
		n = (char *)needle;
	}
	return (NULL);
}
