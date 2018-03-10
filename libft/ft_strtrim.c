/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:44:52 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/12 16:48:25 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*begin;
	char	*start;
	char	*c;

	if (s == NULL)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	start = (char *)--s;
	while (*(s + 1) != '\0')
		++s;
	while ((*s == ' ' || *s == '\n' || *s == '\t') && s != start)
		--s;
	c = malloc((s - start + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	begin = c;
	while (start++ != s)
	{
		*c = *start;
		++c;
	}
	*c = '\0';
	return (begin);
}
