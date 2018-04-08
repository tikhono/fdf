/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:57:48 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/07 21:13:24 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "parser.h"
#include "libft/libft.h"
#include <printf.h>

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

int 	num_of_col(char **buff)//put this function in libft
{
	int 	res;

	res = 0;
	while (buff[res])
		res++;
	return (res);
}

int 	ft_is_num(char *num, int base)//put this function in libft)
{
	char 	*c;

	if (num)
	{
		c = num;
		if ((*c == '-' || *c == '+') && base == 10)
			++c;
		if ((*c == '0') && base == 16)
		{
			++c;
			if (*c == 'x')
				++c;
		}
		while (*c != '\0')
		{
			if (!ft_isdigit(*c) && !((base == 16) && (*c >= 'A' && *c <= 'F')))
				return (0);
			++c;
		}
		return (1);
	}
	return (0);
}

t_pix	***fill(t_pix ***arr, int fd, int i, int j)
{
	char	*line;
	char	**temp;
	char	**buf;
	
	while (get_next_line(fd, &line))
	{
		buf = ft_strsplit(line, ' ');
		free(line);
		j = 0;
		arr[i] = (t_pix **)malloc(sizeof(t_pix *) * (num_of_col(buf) + 1));
		while (buf[j] != NULL)
		{
			temp = ft_strsplit(buf[j], ',');
			if (num_of_col(temp) <= 2)
			{
				if (!ft_is_num(temp[0],10))
					return (NULL);//return NULL from return of free function
				arr[i][j] = (t_pix *)malloc(sizeof(t_pix));
				arr[i][j]->oz = ft_atoi(temp[0]);
				if (temp[1])
				{
					if ((!ft_is_num(temp[1], 16)) && temp[1][0] != '\0')
						return (NULL);//return NULL from return of free function
					arr[i][j]->color = 0x00000000 + ft_atoi(temp[1]);
				}
				else
					arr[i][j]->color = 0x00FFFFFF;
			}
			else
				return (NULL);//return NULL from return of free function
			++j;
		}
		arr[i][j] = NULL;
		free(buf);
		++i;
	}
	arr[i] = NULL;
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
	arr = (t_pix ***)malloc(sizeof(t_pix **) * (rows + 1));
	arr[rows] = NULL;
	return (fill(arr, fd, 0, 0));
}
