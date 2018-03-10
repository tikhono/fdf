/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:43:30 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 18:47:19 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *str)
{
	char	*start;
	char	*end;

	if (str != NULL)
	{
		start = str;
		end = str;
		while (*(end + 1) != '\0')
			++end;
		while (end > start)
		{
			*end ^= *start;
			*start ^= *end;
			*end ^= *start;
			++start;
			--end;
		}
	}
}
