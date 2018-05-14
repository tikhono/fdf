/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/05/14 16:28:47 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "main.h"

t_pix	***ret(t_pix ***arr, char *line)
{
	free(line);
	return (arr);
}

void	del(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
}

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

int		put(t_pix ***arr, char **temp, int i, int j)
{
	if (ft_num_of_rows(temp) <= 2)
	{
		if (!ft_isnum(temp[0], 10))
		{
			del(temp);
			return (1);
		}
		arr[i][j] = (t_pix *)malloc(sizeof(t_pix));
		arr[i][j]->oz = ft_atoi(temp[0]);
		arr[i][j]->x = j;
		arr[i][j]->y = i;
		arr[i][j]->z = arr[i][j]->oz;
		if (temp[1] != NULL)
		{
			if ((!ft_isnum(temp[1], 16)) || temp[1][0] != '\0' || (ft_strlen(temp[1]) >= 10))
			{
				del(temp);
				return (1);
			}
		}
	}
	else
	{
		del(temp);
		return (1);
	}
	del(temp);
	return (0);
}

t_pix	***fill(t_pix ***arr, int fd, t_buff_i *b, int c)
{
	char	*line;
	char	**buf;
	int		rows;
	int 	flag;

	flag = 0;
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
				flag = 1;
			free(buf[b->j]);
			++b->j;
		}
		free(buf);
		++b->i;
		if (flag == 1)
		{
			free(line);
			return (NULL);
		}
	}
	close(fd);
	return (ret(arr, line));
}

t_pix	***parse(char *file)
{
	int			fd;
	int			rows;
	t_buff_i	b;
	t_pix		***arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0 || rows <= 0)
		return (0);
	arr = (t_pix ***)malloc(sizeof(t_pix **) * (rows + 1));
	arr[rows] = NULL;
	b.i = 0;
	b.j = 0;
	return (fill(arr, fd, &b, 0));
}
