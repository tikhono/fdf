/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:18:09 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/12 16:44:43 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	char	*begin;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	c = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	begin = c;
	while (*s1)
	{
		*c = *s1;
		++s1;
		++c;
	}
	while (*s2)
	{
		*c = *s2;
		++s2;
		++c;
	}
	*c = '\0';
	return (begin);
}
