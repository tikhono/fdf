/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:11:25 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/06 22:12:53 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	size = (ft_strlen(s1) + 1) * sizeof(char);
	s2 = malloc(size);
	if (!s2)
		return (NULL);
	s2[size - 1] = '\0';
	size -= 2;
	while ((int)size >= 0)
	{
		s2[size] = s1[size];
		--size;
	}
	return (s2);
}
