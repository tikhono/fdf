/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:10:03 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/18 14:11:30 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*zero(char *str)
{
	str = (char *)malloc(2 * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = '0';
	*(str + 1) = '\0';
	return (str);
}

static char		*magic(char *str, long int num, int neg, int base)
{
	int	rem;
	int	i;

	str = (char *)malloc((ft_find_digit(num, 10) + neg) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num /= base;
	}
	if (neg == 3)
		str[i++] = '-';
	str[i] = '\0';
	return (str);
}

char			*ft_itoa_base(int n, int base)
{
	long int	num;
	char		*str;
	int			neg;

	num = n;
	str = NULL;
	if (num == 0)
		return (zero(str));
	neg = 2;
	if (num < 0 && base == 10)
	{
		neg = 3;
		num = -num;
	}
	str = magic(str, num, neg, base);
	if (str == NULL)
		return (NULL);
	ft_reverse(str);
	return (str);
}
