/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/10 18:15:39 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "main.h"

int		number_of_rows(int fd)
{
	int		res;
	char	*line;
	ssize_t	end;

	res = 0;
	end = 1;
	line = (char *)malloc(sizeof(char *) * 256);
	while (end != 0)
	{
		end = read(fd, line, 256);
		if (end == -1)
			return (-1);
		line[end] = '\0';
		res += ft_count_chars(line, "\n");
	}
	free(line);
	close(fd);
	return (res);
}

t_pix	***erase(t_pix ***arr, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (arr[x] && x < i)
	{
		y = 0;
		while (arr[x][y] && y < j)
		{
			free(arr[x][y]);
			++y;
		}
		free(arr[x]);
		++x;
	}
	free(arr);
	return (NULL);
}

int		put(t_pix ***arr, char **temp, int i, int j)
{
	if (ft_num_of_rows(temp) <= 2)
	{
		if (!ft_isnum(temp[0], 10))
			return (1);
		arr[i][j] = (t_pix *)malloc(sizeof(t_pix));
		arr[i][j]->oz = ft_atoi(temp[0]);
		free(temp[0]);
		arr[i][j]->x = j;
		arr[i][j]->y = i;
		arr[i][j]->z = arr[i][j]->oz;
		if (temp[1] != NULL)
		{
			if ((!ft_isnum(temp[1], 16)) && temp[1][0] != '\0')
				return (1);
			if (ft_strlen(temp[1]) >= 10)
				return (1);
			free(temp[1]);
		}
	}
	else
		return (1);
	free(temp);
	return (0);
}

t_pix	***fill(t_pix ***arr, int fd, t_buff_i *b, int c)
{
	char	*line;
	char	**buf;
	int		rows;

	while (get_next_line(fd, &line))
	{
		buf = ft_strsplit(line, ' ');
		free(line);
		b->j = 0;
		rows = ft_num_of_rows(buf);
		c = (b->i == 0 ? rows : c);
		arr[b->i] = (t_pix **)malloc(sizeof(t_pix *) * (rows + 1));
		arr[b->i][rows] = NULL;
		while (buf[b->j] != NULL)
		{
			if (put(arr, ft_strsplit(buf[b->j], ','), b->i, b->j) || c != rows)
				return (erase(arr, b->i, b->j));
			free(buf[b->j]);
			++b->j;
		}
		free(buf);
		++b->i;
	}
	close(fd);
	return (arr);
}

t_pix	***parse(char *file)
{
	int			fd;
	int			rows;
	t_buff_i	*b;
	t_pix		***arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0 || rows <= 0)
		return (0);
	arr = (t_pix ***)malloc(sizeof(t_pix **) * (rows + 2));
	arr[rows + 1] = NULL;
	b = (t_buff_i *)malloc(sizeof(t_buff_i) * 2);
	b->i = 0;
	b->j = 0;
	return (fill(arr, fd, b, 0));
}
