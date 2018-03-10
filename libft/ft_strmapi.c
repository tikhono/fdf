/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:20:07 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:20:44 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;

	if (s == NULL || f == NULL)
		return (NULL);
	c = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		c[i] = (*f)(i, (char)s[i]);
		++i;
	}
	c[i] = '\0';
	return (c);
}
