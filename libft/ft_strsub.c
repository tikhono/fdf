/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:47:39 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/12 16:47:12 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (s == NULL)
		return (NULL);
	c = malloc((len + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] && i < len)
	{
		c[i] = s[i + start];
		++i;
	}
	c[i] = '\0';
	return (c);
}
