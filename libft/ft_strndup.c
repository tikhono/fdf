/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 14:13:53 by atikhono          #+#    #+#             */
/*   Updated: 2018/03/10 14:21:52 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	size_t	len;
	size_t	i;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc((size) * sizeof(char));
	if (!s2)
		return (NULL);
	s2[size] = '\0';
	i = 0;
	while (i < size && i < len)
	{
		s2[i] = s1[i];
		++i;
	}
	return (s2);
}
