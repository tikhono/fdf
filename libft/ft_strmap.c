/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:56:55 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:44:55 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*c;
	char	*begin;

	if (s == NULL || f == NULL)
		return (NULL);
	c = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	c[ft_strlen(s)] = '\0';
	begin = c;
	while (*s != '\0')
	{
		*c = (*f)((char)*s);
		++c;
		++s;
	}
	return (begin);
}
