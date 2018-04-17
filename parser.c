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
#include "libft/libft.h"

int		number_of_rows(int fd)
{
	int		res;
	char	*line;
	ssize_t	end;

	res = 0;
	end = 1;
	while (end != 0)
	{
		line = (char *)malloc(sizeof(char) * 256);
		end = read(fd, line, 256);
		if (end == -1)
			return (-1);
		line[end]= '\0';
		res += ft_count_chars(line, "\n");
	}
	close(fd);
	return (res);
}

t_pix ***erase(t_pix ***arr)
{
	int 	x;
	int 	y;

	x = 0;
	while (arr[x])
	{
		y = 0;
		while (arr[x][y])
		{
			free(arr[x][y]);
			++y;
		}
		++x;
	}
	free(arr);
	return (NULL);
}

int		put_pix(t_pix ***arr, char **temp, int i, int j)
{
	if (ft_num_of_rows(temp) <= 2)
	{
		if (!ft_isnum(temp[0],10))
			return (1);
		arr[i][j] = (t_pix *)malloc(sizeof(t_pix));
		arr[i][j]->oz = ft_atoi(temp[0]);
		if (temp[1] != NULL)
		{
			if ((!ft_isnum(temp[1], 16)) && temp[1][0] != '\0')
				return (1);
			if (ft_strlen(temp[1]) >= 10)
				return (1);
			arr[i][j]->color = ft_atoi_base(temp[1], 16);
		}
		else
			arr[i][j]->color = 0x00FFFFFF;
	}
	else
		return (1);
	return (0);
}

t_pix	***fill(t_pix ***arr, int fd, int i, int j)
{
	char	*line;
	char	**temp;
	char	**buf;
	int 	rows;

	while (get_next_line(fd, &line))
	{
		buf = ft_strsplit(line, ' ');
		free(line);
		j = 0;
		rows = ft_num_of_rows(buf);
		arr[i] = (t_pix **)malloc(sizeof(t_pix *) * (rows + 1));
		arr[i][rows] = NULL;
		while (buf[j] != NULL)
		{
			temp = ft_strsplit(buf[j], ',');
			if (put_pix(arr, temp,i, j))
				return (erase(arr));
			++j;
		}
		free(buf);
		++i;
	}
	close(fd);
	return (arr);
}

t_pix	***parse(char *file)
{
	int		fd;
	int		rows;
	t_pix 	***arr;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	rows = number_of_rows(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0 || rows <= 0)
		return (0);
	arr = (t_pix ***)malloc(sizeof(t_pix **) * (rows + 2));
	__builtin_printf("%p", arr);
	arr[rows + 1] = NULL;
	return (fill(arr, fd, 0, 0));
}
