/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/01 20:42:06 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int		number_of_rows(int fd)
{
	int		end;
	int		res;
	char	*line;

	res = 0;
	end = 1;
	while (end != 0)
	{
		line = (char *)malloc(sizeof(char *) * 256);
		end = read(fd, line, 256);
		if (end == -1)
			return (-1);
		line[end]= '\0';
		res += ft_count_chars(line, "\n");
	}
	return (res);
}

int		fill(char **arr)
{
	int		i;
	int		j

	while (get_next_line(fd, &line))
	{
		buf = ft_split(line, ' ');
		while (arr[i] != NULL)
		{
		//arr[i][j] = (struct)malloc(sizeof(struct));
		//	copy in arr from buf
			++i;
		}
	}
	return (1);
}

int		parse(char *file)
{
	int		fd;
	int		rows;
	char 	**arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	if (rows <= 0)
		return (0);
	arr = (char **)malloc(sizeof(char **) * rows + 1);
	arr[rows] = NULL;
	if (fill(arr))
		return (1);
	return (0);
}
