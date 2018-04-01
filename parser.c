/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/01 19:46:45 by atikhono         ###   ########.fr       */
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

int		parse(char *file)
{
	int		fd;
	int		rows;
	char	*line;
	char 	**arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	if (rows < 0)
		return (0);
	arr = (char **)malloc(sizeof(char **) * rows + 1);
	while (get_next_line(fd, &line))
	{
		//split line on pixels (by spaces)
		//malloc space on one row of pixels (structures)
		//while (row)
		//{
		//	fill defined structure
		//	go to next structure
		//}
	}
	return (1);
}
