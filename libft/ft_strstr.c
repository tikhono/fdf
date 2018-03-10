/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:14:48 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/07 18:47:49 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *h;
	char *s;
	char *n;

	h = (char *)haystack;
	s = (char *)haystack;
	n = (char *)needle;
	if (!*n)
		return (h);
	while (*h)
	{
		while (*h == *n && *h && *n)
		{
			++h;
			++n;
		}
		if (!*n)
			return (s);
		++s;
		h = s;
		n = (char *)needle;
	}
	return (NULL);
}
