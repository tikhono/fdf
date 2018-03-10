/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:48:51 by atikhono          #+#    #+#             */
/*   Updated: 2017/11/20 17:51:16 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		w;
	char	*cur;

	w = 0;
	cur = (char *)s;
	while (*cur)
	{
		if (*cur != c)
			++w;
		while (*cur != c && *cur != '\0')
			++cur;
		while (*cur == c && *cur != '\0')
			++cur;
	}
	return (w);
}

static int	count_len(char **w_start, char c)
{
	char	*w_end;

	while (**w_start == c && **w_start != '\0')
	{
		++*w_start;
	}
	w_end = *w_start;
	while (*w_end != c && *w_end != '\0')
	{
		++w_end;
	}
	return (int)(w_end - *w_start + 1);
}

static char	**loop(char **str, char *w_start, char c, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < w)
	{
		str[i] = (char *)malloc(count_len(&w_start, c) * sizeof(char));
		if (str[i] == NULL)
		{
			while (i >= 0)
				free(str[i--]);
			free(str);
			return (NULL);
		}
		j = 0;
		while (*w_start != c && *w_start != '\0')
		{
			str[i][j++] = *w_start;
			++w_start;
		}
		str[i++][j] = '\0';
	}
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		w;
	char	*w_start;
	char	**str;

	if (s == NULL)
		return (NULL);
	w = count_words(s, c);
	str = (char **)malloc((w + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	str[w] = NULL;
	w_start = (char *)s;
	return (loop(str, w_start, c, w));
}
